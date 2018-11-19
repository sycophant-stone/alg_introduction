#include<iostream>
#include<algorithm>
#include <map>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;
//#define OPEN_LOG
#ifdef OPEN_LOG
#define julyex_logv printf
#else
#define julyex_logv 
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
static void show_data(const char *s, int dat[],int len)
{
    julyex_logv("%s\n",s);
    for(int i=0;i<len;i++){
        julyex_logv("%d ",dat[i]);
    }
    julyex_logv("\n");
}
static void _find_min_k_num(int dat[],int k,int l,int r)
{
    int pivot,i=l,j=r;
    julyex_logv("[_find_min_k_num]: k:%d, l:%d, r:%d\n",k,l,r);
    show_data("before median3",dat,10);
    pivot=median3(dat,0,r);
    julyex_logv("l:%d,r:%d, pivot :%d\n",l,r,pivot);
    j=j-1;
    julyex_logv("i:%d, j:%d\n",i,j);
    while(1){
        while(dat[++i]<pivot){};
        while(dat[--j]>pivot){};
        julyex_logv("i:%d, j:%d\n",i,j);
        show_data("find ij",dat,10);
        if(i>j){
            julyex_logv("i:%d, j:%d\n",i,j);
            if(i>k){ // 注意这个判断条件
                _find_min_k_num(dat,k,l,i-1);
            }else if (i<k-1){
                _find_min_k_num(dat,k,i+1,r); //i,r-1 注意这个
            }else{
                julyex_logv("find! i:%d\n",i);
            }
            break;
        }else {
            julyex_logv("dat[i:%d]:%d, dat[j:%d]:%d\n",i,dat[i],j,dat[j]);
            std::swap(dat[i],dat[j]);
        }
    }
    show_data("after recurrent",dat,10);
}

static void find_min_k_num()
{
    int test_dat[]={8, 1, 4, 9, 6, 3, 5, 2, 7, 0};
    const int k=3;
    int l= sizeof(test_dat) / sizeof(test_dat[0]);
    julyex_logv("l:%d\n",l);
    _find_min_k_num(test_dat,k,0,l-1);
    for(int i=0;i<k;i++){
        julyex_logv("[k:%d]:%d\n",k,test_dat[i]);
    }
}

/*
 * 对于有序数组,TwoSum的时间复杂度为O(nlogn),空间复杂度为O(1)
 *****/
static void TwoSum(int a[],int len, int sum)
{
    int begin=0;
    int end=len-1;
    while(begin<end){
        if (a[begin]+a[end]>sum)
            end--;
        else if (a[begin]+a[end]<sum)
            begin++;
        else{
            printf("%d and %d\n",a[begin],a[end]);
            begin++;
            end--;
        }
    }
    
}

static void find_fix_sum_num()
{
    int a[10] = {9,6,3,8,5,2,7,4,1,0};
    /*1. sort
     ******/
    printf("the origin array:\n");
    for (int i=0;i<10;i++){
        //printf("a[%d]=%c \n",i,a[i]+'0');
        printf("%d ",a[i]);
    }
    printf("\n");
    sort(a,a+10);
    printf("after sorting:\n");
    for (int i=0;i<10;i++){
        //printf("a[%d]=%c \n",i,a[i]+'0');
        printf("%d ",a[i]);
    }
    printf("\n");

    /*2. TwoSum
     ******/
    TwoSum(a,10,7);
    
}

void julyex_entry()
{
//    find_min_k_num();
    find_fix_sum_num();
}
