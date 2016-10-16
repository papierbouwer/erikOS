#ifndef SHELL_H
#define SHELL_H
#include "system.h"
#include "string.h"
#include "kb.h"
#include "screen.h"
#include "types.h"
#include "util.h"

void launchShell(int n);

void sum();
void echo();
void sort();
void fill_array(int arr[],int n);
void print_array(int arr[],int n);
void insertion_sort(int arr[],int n,int order); //1 is increassing, 0 is descreassing
int sum_array(int arr[],int n);
void fibonaci();
int fibo(int n);
int gcdCouple(int a,int b);
void gcd();
void print_matrix(int matrix[][100],int rows,int cols);
void setBackgroundColor();
void multiply();
void help();


#endif
