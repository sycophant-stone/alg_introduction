#include<iostream>
#include <map>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;
//#define OPEN_LOG
#ifdef OPEN_LOG
#define leet_logv printf
#else
#define leet_logv 
#endif

static int median3( int a[], int left, int right )
//下面的快速排序算法实现之一，及通过三数取中分割法寻找最小的k个数的快速选择SELECT算法都要调用这个median3函数
{ 
    int centor;
    centor=(left + right)/2;
    if (a[left]>a[centor]) {
        std::swap(a[left], a[centor]);
    }
    if (a[left]>a[right]) {
        std::swap(a[left], a[right]);
    }
    if (a[centor]>a[right]) {
        std::swap(a[centor], a[right]);
    }
    std::swap(a[centor], a[right-1]);
    return a[right-1];
} 

static void _find_min_k_num(int dat[],int k,int l)
{
    int pivot;
    pivot=median3(dat,0,l-1);
    printf("len:%d, pivot :%d\n",l,pivot);
}

static void find_min_k_num()
{
    int test_dat[]={8, 1, 4, 9, 6, 3, 5, 2, 7, 0};
    int k=3;
    int l= sizeof(test_dat) / sizeof(test_dat[0]);
    printf("l:%d\n",l);
    _find_min_k_num(test_dat,k,l);
    
}

void julyex_entry()
{
    find_min_k_num();
}