#include<iostream>
#include<algorithm>
#include <map>
#include <list>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;
#define OPEN_LOG
#ifdef OPEN_LOG
#define julyex_logv printf
#define JULY_LOGI(format,...) printf("[Line: %05d]: "format"\n", __LINE__, ##__VA_ARGS__)  
#else
#define julyex_logv 
#define JULY_LOGI(format,...) 
#endif
#define ENTER JULY_LOGI("ENTER\n");
#define EXIT  JULY_LOGI("EXIT\n");

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
// 寻找无序数组中最小的k个数.
//    采用快速选择法.
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


/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/

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
// 在无序数组中,找到和为定值的某两个数的组合.
//    先排序成有序
//    前后依次求和做判断.
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


/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/

static int median3sort( int a[], int left, int right )
//下面的快速排序算法实现之一，及通过三数取中分割法寻找最小的k个数的快速选择SELECT算法都要调用这个median3函数
{ 
    int centor;
    centor=(left + right)/2;
    //printf("[median3sort]: l:%d, a[%d]:%d, r:%d, a[%d]:%d, centor:%d\n", left, left, a[left], right, right, a[right], centor);
    if (a[left]>a[centor]) {
        std::swap(a[left], a[centor]);
    }
    if (a[left]>a[right]) {
        std::swap(a[left], a[right]);
    }
    if (a[centor]>a[right]) {
        std::swap(a[centor], a[right]);
    }
    return a[centor];
} 
//static int bfirst=2;
static void quick_sort(int a[],int l, int r)
{
    int pivot,centor,i,j;
    pivot=median3sort(a,l,r);
    #if 0
    if (bfirst>0){
        bfirst--;
        printf("after median3sort:\n");
        for (int i=0;i<10;i++){
            //printf("a[%d]=%c \n",i,a[i]+'0');
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    #endif
    centor=(l+r)/2;
    i=l;
    j=r;
    while(i<j){   // 注意这个交换条件
        while(a[i]<pivot){i++;};
        while(a[j]>pivot){j--;};
        //printf("[quick_sort]: l:%d, a[%d]:%d, r:%d, a[%d]:%d, pivot:%d, centor:%d\n", i, i, a[i], j, j, a[j], pivot, centor);
        if(i>=j)
            break;
        std::swap(a[i],a[j]);
    }
    if (l>=r)     // 注意这个退出条件.
        return ;
    //printf("[quick_sort]: l:%d, a[%d]:%d, r:%d, a[%d]:%d, pivot:%d, centor:%d\n", l, l, a[l], r, r, a[r], pivot, centor);
    quick_sort(a,l,centor);
    quick_sort(a,centor+1,r);
    
}

static void quick_sort_case()
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
    quick_sort(a,0,10-1);
    printf("after sorting:\n");
    for (int i=0;i<10;i++){
        //printf("a[%d]=%c \n",i,a[i]+'0');
        printf("%d ",a[i]);
    }
    printf("\n");

}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/



static void merge_two_arrays(int a[], int alen, int b[], int blen)
{
    int *c,i=0,j=0,clen,k=0;
    clen=alen+blen;
    c = (int*)malloc(clen);
    while(alen>0&&blen>0){
        if (a[i]>b[j]){
            c[k++]=b[j++];
            blen--;
        }else{
            c[k++]=a[i++];
            alen--;
        }
    }
    while(alen>0){
            c[k++]=a[i++];
            alen--;
    }
    while(blen>0){
            c[k++]=b[j++];
            blen--;
    }
    
    for(int m=0;m<clen;m++){
        printf("%d ",c[m]);
    }
    printf("\n");
}

// 合并两个无序数组
static void merge_two_arrays_case()
{
    int a[5] = {9,6,3,8,5};
    int b[5] = {2,7,4,1,0};
    quick_sort(a,0,5-1);
    quick_sort(b,0,5-1);
    merge_two_arrays(a,5,b,5);
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/

// m个珠子
// n种颜色
static int find_min_len_orbs(int a[],int m,int n)
{
    int *flags,product=1,i;
    flags=(int*)malloc(n);
    memset(flags,0,n);
    for(i=0;i<m;i++){
        flags[a[i]]++;
        product=1;
        for(int j=0;j<n;j++){
            product*=flags[j];
        }
        if(product>0)
            break;
        
    }
    free(flags);
    printf("[find_min_len_orbs]: minl:%d\n",i);
    return i;
}
// 一串首尾相连的珠子(m个)，有N种颜色(N<=10)，设计一个算法，取出其中一段，要求包含所有N中颜色，并使长度最短。
static void find_min_len_orbs_case()
{
    int a[10] = {2,1,0,1,1,2,1,0,1,1}; // 不同值代表不同颜色.
    int minl;
    minl=find_min_len_orbs(a,10,3);
    
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/

// 解法1

// 输入两个整数n 和m，从数列1，2，3.......n 中随意取几个数, 使其和等于m ,要求将其中所有的可能组合列出来
list<int> list_saver;
static void find_sum_of_k_num(int a[],int n,int sum)
{
    if(sum<=0||n<=0){
        return ;
    }
    JULY_LOGI("sum:%d,n:%d\n",sum,n);
    if(sum==n){
        //JULY_LOGI("sum:%d,n:%d\n",sum,n);
        for(list<int>::iterator iter=list_saver.begin();iter!=list_saver.end();iter++){
            printf("%d ",*iter);
        }
        printf("%d\n",n);
    }
    list_saver.push_front(n);
    find_sum_of_k_num(a,n-1,sum-n);
    list_saver.pop_front();
    find_sum_of_k_num(a,n-1,sum);
}

// 解法2 回溯法+剪枝


static void find_sum_of_k_num_backtracking(int t, int k, int r, int& M, bool& flag, bool* X)
{
    X[k]=true; //对于第k个数,设成true,紧接着做如下判断.如果k和t之和为期望值M,则找到这些值,打印它们.
    JULY_LOGI("X[%d]=%d,t:%d,k:%d,r:%d,M:%d\n",k,X[k],t,k,r,M);
    if(t+k==M){
        // 找到
        flag=true;
        for(int i=1;i<=k;i++){ //对于X,从1到k共k+1个.
            if(X[i]==1){
                printf("%d ",i);
            }
        }
        printf("\n");
    }else{
        // t+k!=M 有可能, t+k<M 或者 t+k>M
        if(t+k+(k+1)<=M){ // 条件1
            // 处理t+k<M的情况.
            find_sum_of_k_num_backtracking(t+k,k+1,r-k,M,flag,X); // 如果把k吸收之后,t+k+k+1仍然小于M,那肯定要把k包含掉.然后递归左树.
        }
        if((t+r-k>=M)&&(t+(k+1)<=M)){ // 条件2.  注意这里并非else if的情况.也就是说在条件1满足后,也可以满足条件2.这个也是打印出所有组合的关键. 
                                      //         当然在t+k不满足M时候,要跳过k来看后面是否满足,
                                      //         除此之外,当t+k满足M的时候,在记录好k之后也要查一下k之后的是否也满足,这个是打印出所有组合的关键.
            // 满足条件1: t+k!=M
            // 满足条件2: t+k+(k+1)>M
            // 尝试抛弃k值.所谓抛弃,则X[k]为false
            X[k]=false;
            find_sum_of_k_num_backtracking(t,k+1,r-k,M,flag,X); // 因为抛弃k值,所以t不用加k了.
        }
    }
}

static void find_sum_of_k_num_case()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int N=10,M=10;
    //JULY_LOGI("ENTER1\n");
    //find_sum_of_k_num(a,10,10);
    //JULY_LOGI("EXIT1\n");
    
    JULY_LOGI("ENTER2 backtracking\n");
    bool* X=(bool*) malloc(sizeof(bool)*(10));
    memset(X,false,sizeof(bool)*(10));
    int sum=(N+1)*N/2;// 最大的和
    bool f=false;
    find_sum_of_k_num_backtracking(0,1,sum,M,f,X);
    if(f==false){
        JULY_LOGI("not found\n");
    }
    JULY_LOGI("EXIT2 backtracking\n");
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/

// 给定一个数组,数组里有正负,数组中连续的一个或者多个组成一个子数组,求子数组的最大的值.
static void find_max_continuous_subarray(int a[],int len)
{
    int cur=0,max=a[0];
    int begin=-1,end=-1;
    for (int i=0;i<len;i++){
        if(cur>=0){
            cur+=a[i];
            if(begin==-1){
                begin=i;
            }
        }else {
            cur=a[i];
            begin=i;
            end=-1;
        }
        if(max<=cur){
            max=cur;
            end=i;
            //JULY_LOGI("max:%d,cur:%d,i:%d\n",max,cur,i);
        }
    }
    //JULY_LOGI("max:%d,begin:%d,end:%d\n",max,begin,end);
    if(begin<0||begin>end||end<0){
        JULY_LOGI("Error\n");
        return ;
    }
    for(int i=begin;i<=end;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("max:%d\n",max);
}

static void find_max_continuous_subarray_case()
{
    ENTER
    int a[8]={1,-2,3,10,-4,7,2,-5};
    find_max_continuous_subarray(a,8);
    EXIT
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/

// 一个台阶有n级,如果一次可以跳一级,也可以跳两级.总共多少种跳法.

static int fibonacci(int n)
{
    int result[3]={0,1,2};
    if (n<2){
        return result[n];
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

static void fibonacci_staris_case()
{
    int n=10,ret=0;
    ret=fibonacci(n);
    JULY_LOGI("ret:%d\n",ret);
}


/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// 奇偶选择问题.把一串数的奇数放在左边,偶数放在右边.
// 可以考虑快排序的思想.
static bool isodds(int x)
{
    return (x%2==1);
}
static void odd_even_sort(int a[],int len)
{
    int begin=0,end=len-1;
    while(begin<=end){
        while(isodds(a[begin])){
            begin++;
        }
        while(!isodds(a[end])){
            end--;
        }
        if(begin>end)
            break;
        //JULY_LOGI("begin:%d,end:%d,a[begin]:%d,a[end]:%d\n",begin,end,a[begin],a[end]);
        swap(a[begin],a[end]);
    }
}
static void odd_even_sort_case()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    odd_even_sort(a,10);
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
enum enumType {BLUE,WHITE,RED};
static void dutch_flag_sort(int a[],int len)
{
    int begin=0,middle=len/3,end=len/3*2;
    JULY_LOGI("begin:%d,middle:%d,end:%d\n",begin,middle,end);
    while((begin<middle)&&(middle<end)){
        JULY_LOGI("begin:%d,middle:%d,end:%d\n",begin,middle,end);
        if((begin<len/3)&&(middle<len/3*2)&&(a[middle]<WHITE)){
            swap(a[begin],a[middle]);
            if(a[middle]==WHITE)
                middle++;
            begin++;
        }
        if((middle<len/3*2)&&(a[middle]==WHITE)){
            middle++;
        }
        if((end<len)&&(a[middle]>WHITE)){
            swap(a[middle],a[end]);
            if(a[middle]==WHITE)
                middle++;
            end++;
        }
        if((begin==len/3)&&(middle==len/3*2)&&(end==len))
            break;
    }
    for(int i=0;i<len;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

static void dutch_flag_case()
{
    int a[9]={2,0,1,0,0,2,1,1,2};
    dutch_flag_sort(a,9);
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// 完美洗牌算法.分成几个小部分.
// 位置替换算法.

static void location_replace_case(char a[],int len)
{
    char* b=(char*)malloc(sizeof(char)*len);
    int n=len/2;
    for(int i=1;i<=len;i++){
        JULY_LOGI("i:%d,2i:%d,2n+1:%d,mod:%d,a[i-1:%d]:%c\n",i,2*i,2*n+1,(2*i)%(2*n+1),i-1,a[i-1]);
        b[(2*i)%(2*n+1)-1]=a[i-1]; // 注意b[?]和a[?]中都有一个-1操作,这个是为了数学公式从1开始,但是数组从0开始,保持一个偏移的一致性.
    }
    for(int i=0;i<len;i++){
        a[i]=b[i];
        printf("%c ",a[i]);
    }
    printf("\n");
    free(b);
}

static void perfect_shuffle_case()
{
    char a[9]="abcdABCD"; // 最终目的到 "aAbBcCdD"
    location_replace_case(a,8);//  此阶段===> "AaBbCcDd"
    
}

void julyex_entry()
{
//    find_min_k_num();
//    find_fix_sum_num();
//    quick_sort_case();
//    merge_two_arrays_case();
//    find_min_len_orbs_case();
//    find_sum_of_k_num_case();
//    find_max_continuous_subarray_case();
//    fibonacci_staris_case();
//    odd_even_sort_case();
//    dutch_flag_case();
    perfect_shuffle_case();
}
