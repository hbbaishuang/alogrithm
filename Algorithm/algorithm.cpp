#include "algorithm.h"
#include <iostream>
#include <assert.h>
using namespace std;

//int nΪ���ӵĸ�������Ŀ˵����64������ ��a�ᵽc ����b
//zhangpeng 2013-3-16
void hanoi(int n, char a, char b, char c, int& count)
{
    if (n == 1)
    {
        //n==1ֱ�Ӵ�A�ƶ���C
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

//Fibonacci���� f(n) = f(n-1) + f(n-2)
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

//ѡ������
//zhangpeng 2013-3-17
void selection_sort(int number[], int n)
{
    //ÿ���ҵ���С�ķŵ�����ͷ��
    int i, j, m;
    for (i = 0; i < n - 1; ++i)
    {
        m = i;//����i��С
        for(j = i; j < n; ++j)
        {
            if (number[m] > number[j])
            {
                m = j;
            }
        }
        if (m != i)
        {
            //�ҵ���С�Ľ���һ��
            int t = number[i];
            number[i] = number[m];
            number[m] = t;
        }
    }
}

//��������
//zhangpeng 2013-3-17
void input_sort(int number[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int tmp = number[i];
        int j = i - 1;
        while (tmp < number[j] && j >= 0)
        {
            //�ҵ���һ��������tmp��λ��
            number[j + 1] = number[j];
            --j;
        }
        //�������λ�õĺ���
        number[j + 1] = tmp;
    }
}

//ð������
//zhangpeng 2013-3-17
void bubble_sort(int number[], int n)
{
    int count = 0;
    int mv = 0;//��λ
    //ֻ���ҵ�n-1�����������ĺ��ˣ�����ֻ��Ҫn-1��
    for (int i = 0; i < n - 1; ++i)
    {
        bool changed = false;
        for (int j = mv; j < n - 1 - i; ++j)
        {
            
            //��������{1,2,3,8,4,5,6,7}
            //����ͳ�Ʋ�ͬ������Ч��,ԭ��(28��)����mv��(17��)����break��(13��)����mv��break��(11��)
            ++count;
            if (number[j] > number[j + 1])
            {
                //��ķŵ�����
                int tmp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = tmp;
                if (!changed)
                {
                    //����ǰ��û�н����Ļ��´β���Ҫ��ͷ��ʼ�Ƚϣ�ֻ�豾��ѭ����һ�γ��ֽ�����λ�õ�ǰ��һ��λ�ÿ�ʼ�Ƚ�
                    //��i��i+1���������i-1��ʼ�Ƚϣ���һ�αȽ�i-1��i�Ĵ�С
                    //��{0,2,21,32,10,14,81}
                    //��һ�γ��ֽ�����λ��Ϊ32��10�����´�ֻ���21��ʼ�ͽ������10�Ƚ�
                    mv = j - 1;
                    changed = true;
                }
            }
        }
        //����û�н����������Ѿ�������ϣ���ǰ����
        if (!changed)
        {
            break;//ע�͵���䣬��ȥ��mv��Ϊfor (int j = 0) ��Ϊԭ���޸Ľ���ð������
        }
    }
    printf("\ncount: %d\n", count);
}
