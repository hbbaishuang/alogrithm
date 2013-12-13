#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

//河内之塔Towers of Hanoi
void hanoi(int n, char a, char b, char c, int& count);
//Fibonacci数列 f(n) = f(n-1) + f(n-2)
int fibonacci(int n);
//杨辉三角
void yanghui(int n);

//选择排序
void selection_sort(int number[], int n);
//插入排序
void input_sort(int number[], int n);
//冒泡排序
void bubble_sort(int number[], int n);

#endif
