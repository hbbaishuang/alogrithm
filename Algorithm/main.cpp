#include "algorithm.h"
#include <iostream>
#include <assert.h>
#include "LoopQueue.h"
using namespace std;

void hanoi_test()
{
    int n = 0;
    char enter;
    int count = 0;
    printf("ÇëÊäÈëÊı×Ö:");
	
    while (n <= 0)
    {
        scanf("%d%c", &n,&enter);
    }
    hanoi(n, 'A', 'B', 'C', count);
    printf("Move %d plate need %d steps", n, count);
}

void fibonacci_test()
{
    int n = 0;
    char enter;
    printf("ÊäÈëN:");
    scanf("%d%c", &n, &enter);
    assert(n > 0 && "n must larger than 0");
    for (int i = 1; i <= n; ++i)
    {
        printf("%d\n", fibonacci(i));
    }
}
void sort_test()
{
    int number[] = {1,2,3,8,4,5,6,7};
    int len = sizeof(number)/sizeof(int);
    printf("length of number:%d\n", len);
    printf("before sort:");
    for (int i = 0; i < len; ++i)
    {
        printf("%d ", number[i]);
    }
    printf("\nafter sort:");

    //selection_sort(number, len);
    //input_sort(number, len);
    bubble_sort(number, len);

    for (int i = 0; i < len; ++i)
    {
        printf("%d ", number[i]);
    }
}

void LoopQueue_test()
{
    LoopQueue<int> queue;
    for (int i = 0; i < 100; ++i)
    {
        queue.push_back(i);
    }
    //queue.push_back(1);
    //queue.push_back(2);
    int n;
    n = queue.size();
    queue.pop_front(n);
    n = queue.size();
    queue.pop_front(n);
    queue.front(n);
    queue.pop_front(n);
    n = queue.size();
    for (int i = 0; i < 100; ++i)
    {

        queue.pop_front(n);
    }
    n = queue.size();
    for (int i = 0; i < 1; ++i)
    {
        queue.push_back(i);
    }
    n = queue.size();
    queue.pop_front(n);
    n = queue.size();
}
int main()
{
    //hanoi_test();
    //fibonacci_test();
    //sort_test();
    //LoopQueue_test();
    
    cin.get();
    return 0;
}