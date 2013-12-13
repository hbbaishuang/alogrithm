#include "algorithm.h"
#include <iostream>
#include <assert.h>
using namespace std;

//int n为盘子的个数，题目说的是64个盘子 从a搬到c 经过b
//zhangpeng 2013-3-16
void hanoi(int n, char a, char b, char c, int& count)
{
    if (n == 1)
    {
        //n==1直接从A移动到C
        printf("Move %d plate from %c to %c\n", n, a, c);
        ++count;
    }
    else
    {
        hanoi(n-1, a, c, b, count);
        printf("Move %d plate from %c to %c\n", n, a, c);
        ++count;
        hanoi(n - 1, b, a, c, count);
    }
}

//Fibonacci数列 f(n) = f(n-1) + f(n-2)
//zhangpeng 2013-3-16
int fibonacci(int n)
{
    assert(n > 0 && "n must large than 0");
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

//选择排序
//zhangpeng 2013-3-17
void selection_sort(int number[], int n)
{
    //每次找到最小的放到数组头部
    int i, j, m;
    for (i = 0; i < n - 1; ++i)
    {
        m = i;//假设i最小
        for(j = i; j < n; ++j)
        {
            if (number[m] > number[j])
            {
                m = j;
            }
        }
        if (m != i)
        {
            //找到更小的交换一下
            int t = number[i];
            number[i] = number[m];
            number[m] = t;
        }
    }
}

//插入排序
//zhangpeng 2013-3-17
void input_sort(int number[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int tmp = number[i];
        int j = i - 1;
        while (tmp < number[j] && j >= 0)
        {
            //找到第一个不大于tmp的位置
            number[j + 1] = number[j];
            --j;
        }
        //插入这个位置的后面
        number[j + 1] = tmp;
    }
}

//冒泡排序
//zhangpeng 2013-3-17
void bubble_sort(int number[], int n)
{
    int count = 0;
    int mv = 0;//移位
    //只需找到n-1个大数，就拍好了，所以只需要n-1次
    for (int i = 0; i < n - 1; ++i)
    {
        bool changed = false;
        for (int j = mv; j < n - 1 - i; ++j)
        {
            
            //测试数据{1,2,3,8,4,5,6,7}
            //用来统计不同方法的效率,原版(28次)、带mv版(17次)、带break版(13次)、带mv带break版(11次)
            ++count;
            if (number[j] > number[j + 1])
            {
                //大的放到后面
                int tmp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = tmp;
                if (!changed)
                {
                    //由于前面没有交换的话下次不需要从头开始比较，只需本次循环第一次出现交换的位置的前面一个位置开始比较
                    //如i和i+1交换后，需从i-1开始比较，再一次比较i-1与i的大小
                    //如{0,2,21,32,10,14,81}
                    //第一次出现交换的位置为32、10，则下次只需从21开始和交换后的10比较
                    mv = j - 1;
                    changed = true;
                }
            }
        }
        //本次没有交换，代表已经排序完毕，提前结束
        if (!changed)
        {
            break;//注释掉这句，并去掉mv改为for (int j = 0) 即为原版无改进的冒泡排序
        }
    }
    printf("\ncount: %d\n", count);
}
