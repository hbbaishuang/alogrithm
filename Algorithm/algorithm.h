#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

//����֮��Towers of Hanoi
void hanoi(int n, char a, char b, char c, int& count);
//Fibonacci���� f(n) = f(n-1) + f(n-2)
int fibonacci(int n);
//�������
void yanghui(int n);

//ѡ������
void selection_sort(int number[], int n);
//��������
void input_sort(int number[], int n);
//ð������
void bubble_sort(int number[], int n);

#endif
