#include<iostream>
#include <map>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <algorithm>

#include<unordered_set>

using namespace std;
//#define OPEN_LOG
#ifdef OPEN_LOG
#define leet_logv printf
#define LC_LOGI(format,...) printf("[lc][%s]:[Line: %05d]: "format"\n", __FUNCTION__,__LINE__, ##__VA_ARGS__)  

#else
#define leet_logv 
#define LC_LOGI
#endif

#define LC_LOGI (printf("%s(%d)-<%s>: ",__FILE__, __LINE__, __FUNCTION__), printf)

#if 0
static int* twoSum(int nums[], int target) 
{   
    int len=strlen(nums);
    if (nums == NULL || len <= 1) {
        return new int[2];
    }
   Map<Integer, Integer> map = new HashMap<Integer, Integer>();
   // key = target - nums[i], just one solution
   for (int i = 0; i < len; i++) {
       map.put(target - nums[i], i);
   }
   for (int i = 0; i < len; i++) {
       Integer v = map.get(nums[i]);
       // can't use itself
       if (v != NULL && v != i) {
           return new int[] { i + 1, v + 1 };
       }
   }
        return NULL;
}
void test_two_sum()
{
	int numbers=[2, 7, 11, 15], target=9;
	int *rets;
	rets = twoSum(numbers,target);
	for(int i=0;i<rets.length;i++) {
		cout<<"rets[i]"<<endl;
	}
}
#endif


class Solution {
public:
    vector< vector<int> > generateMatrix(int n) {
        int d=n-1;
        int x=n-d-1,y=0;
        int num=1;
        vector< vector<int> > res;
        res.resize(n);
        for(int i=0;i<n;i++) res[i].resize(n);
        
        while(d>0){
            x=(n-d)/2;
            y=(n-d)/2;
            leet_logv("d:%d,start x,y:%d,%d\n",d,x,y);
            
            for(int i=0;i<d;i++) {
                res[x][y+i]=num++;
                leet_logv("res[%d][%d]:%d\n",x,y+i,res[x][y+i]);
            }
            y+=d;
            leet_logv("finish 1st,x,y:%d,%d\n",x,y);
            for(int i=0;i<d;i++) {
                res[x+i][y]=num++;
                leet_logv("res[%d][%d]:%d\n",x+i,y,res[x+i][y]);
            }
            x+=d;
            leet_logv("finish 2ed,x,y:%d,%d\n",x,y);
            for(int i=0;i<d;i++) {
                res[x][y-i]=num++;
                leet_logv("res[%d][%d]:%d\n",x,y-i,res[x][y-i]);
            }
            y-=d;
            leet_logv("finish 3rd,x,y:%d,%d\n",x,y);
            for(int i=0;i<d;i++) {
                res[x-i][y]=num++;
                leet_logv("res[%d][%d]:%d\n",x-i,y,res[x-i][y]);
            }
            leet_logv("finish 4th,x,y:%d,%d\n",x,y);
            x-=d;
            d-=2;
        }
        if(d==0) res[(n-1)/2][(n-1)/2]=num;
        leet_logv("res[%d][%d]:%d\n",x,y,res[x][y]);
        return res;
    }
};
/**螺旋矩阵 II
20 / 20 个通过测试用例
状态：通过
执行用时：4 ms
提交时间：0 分钟之前
**/
static void spiral_matrix_ii(int n)
{
    Solution a;
    vector< vector<int> > vec;
    vector<int>::iterator it;
    vector<vector<int> >::iterator iter;
    vector<int> vec_tmp;
    printf("[spiral_matrix_ii]: %d\n",n);
    vec=a.generateMatrix(n);
    
    for(iter = vec.begin(); iter != vec.end(); iter++)
    {
        vec_tmp = *iter;
        for(it = vec_tmp.begin(); it != vec_tmp.end(); it++)
            cout << *it << " ";
        cout << endl;
    }    
    
}



static void spiral_matrix_ii_case()
{
    LC_LOGI("E");
    spiral_matrix_ii(3);
    spiral_matrix_ii(4);
    spiral_matrix_ii(5);
    LC_LOGI("X");
}



/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#27 remove elements
// 对于一个给定的数组，删除其中所有等于一个特定值的数

static int removeElements(vector<int> &nums,int val)
{
    int j=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=val){
            nums[j++]=nums[i];
        }
    }
    for(int i=0;i<j;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
    LC_LOGI("cnt:%d\n",j);
    return j;
}

static void lc27__removeElements_case()
{
    int a[5]={1,2,3,2,2};
    vector<int> nums(a,a+5);
    
    removeElements(nums,2);
}


/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#26 RemoveDuplicatesfromSortedArray
// 对于有序数组,删除多余成员.
static int RemoveDuplicatesfromSortedArray(vector<int> & nums)
{
    int s=0;
    int len=nums.size();
    for(int i=0;i<len;i++){
        if(i+1<len && nums[i]==nums[i+1]){
            continue;
        }else{
            nums[s++]=nums[i];
        }
    }
    for(int i=0;i<s;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
    return s;
}

static void lc26__RemoveDuplicatesfromSortedArray_case()
{
    int a[10]={1,2,2,2,3,4,4,5,6,7};
    vector<int> nums(a,a+10);
    RemoveDuplicatesfromSortedArray(nums);
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#80 RemoveDuplicatesfromSortedArray_II
// 对一个给定的数组进行筛选，同样的数字最多保留2个，求筛选后的剩余数字个数。

static int RemoveDuplicatesfromSortedArray_II(vector<int> &nums)
{
    int len =nums.size(),j=0;
    vector<int> save(nums);
    std::fill(save.begin(), save.end(), 0);
    save[0]=nums[0];
    save[1]=nums[1];
    j=2;
    for(int i=2;i<len;i++){ 
        //LC_LOGI("i:%d,j:%d,nums[i]:%d,nums[i-1]:%d,nums[i-2]:%d\n",i,j,nums[i],nums[i-1],nums[i-2]);
        if(nums[i]!=nums[i-1]||nums[i]!=nums[i-2]){
            save[j++]=nums[i];
            //LC_LOGI("i:%d,j:%d,save[j]:%d,nums[i]:%d\n",i,j-1,nums[i],save[j-1]);
        }
    }
    for(int i=0;i<j;i++){
        printf("%d ",save[i]);
    }
    printf("\n");
    printf("cnt:%d\n",j);
    return j;
    
}

static void lc80__RemoveDuplicatesfromSortedArray_II_case()
{
    int a[6]={1,1,1,2,2,3},cnt=0;
    vector<int> nums(a,a+6);
    
    cnt=RemoveDuplicatesfromSortedArray_II(nums);
}


/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// Helper

static void print_int_vector(vector<int> &nums)
{
    for(int i=0;i<nums.size();i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#189 RotateArray
// 翻转数组

// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
static void RotateArray_I(vector<int> &nums,int n,int k)
{
    vector<int> temp(nums);
    LC_LOGI("before taking action\n");
    print_int_vector(nums);
    for(int i=0;i<n;i++){
        nums[(i+k)%n]=temp[i];
    }
    LC_LOGI("after taking action\n");
    print_int_vector(nums);
}
static void RotateArray_II(vector<int> &nums,int n,int k)
{
    // 1. 翻转前n-k
    // 2. 翻转后k
    // 3. 整体翻转.
    
    std::reverse(nums.begin(),nums.begin()+n-k);
    std::reverse(nums.begin()+n-k,nums.end());
    std::reverse(nums.begin(),nums.end());
    print_int_vector(nums);
}

static void lc189__RotateArray_case()
{
    int a[9]={1,2,3,4,5,6,7,8,9},n,k;
    LC_LOGI("E");
    vector<int> nums(a,a+9);
    vector<int> temp(nums);
    n=nums.size();
    k=3;
    LC_LOGI("methods:I");
    RotateArray_I(nums,n,k);
    nums=temp;
    LC_LOGI("methods:II");
    RotateArray_II(nums,n,k);
    LC_LOGI("X");
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#41 first missing positive

// 这道题让我们找缺失的首个正数，由于限定了O(n)的时间，所以一般的排序方法都不能用，最开始我没有看到还限制了空间复杂度，所以想到了用HashSet来解，这个思路很简单，第一遍遍历数组把所有的数都存入HashSet中，并且找出数组的最大值，下次循环从1开始递增找数字，哪个数字找不到就返回哪个数字，如果一直找到了最大的数字，则返回最大值+1

static int firstMissingPositive_I(vector<int> &nums)
{
    int mx=0;
    unordered_set<int> s;
    for(num:nums){
        if(num<=0)
            continue;
        s.insert(num);
        mx=max(num,mx);
    }
    for(int i=1;i<mx;i++){
        if(s.count(i)==0)
            return i;
    }
    return mx+1;
    
}
// 规定一个规则, a[i]==i+1;的规则,不满足就要交换.
static int firstMissingPositive_II(vector<int> &nums)
{
    int n=nums.size();
    for(int i=0;i<n;){
        if(nums[i]!=i+1 && nums[i]>=1 && nums[i]<=n&& nums[i]!=nums[nums[i]-1]){
            swap(nums[i],nums[nums[i]-1]);
        }else{
            i++;
        }
    }
    for(int i=0;i<n;i++){
        if(nums[i]!=i+1)
            return i+1;
    }
    return n+1;
}

static void lc41__FirstMissingPositive_case()
{
    int a[6]={-1,7,8,9,11,12},ret=-1;
    vector<int> nums(a,a+6);
    vector<int> temp=nums;
    LC_LOGI("E\n");
    LC_LOGI("motheds:I\n");
    ret=firstMissingPositive_I(nums);
    LC_LOGI("find! %d\n",ret);
    LC_LOGI("motheds:II\n");
    ret=-1;
    nums=temp;
    ret=firstMissingPositive_II(nums);
    LC_LOGI("find! %d\n",ret);
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#299 
//这道题提出了一个叫公牛母牛的游戏，其实就是之前文曲星上有的猜数字的游戏，有一个四位数字，你猜一个结果，然后根据你猜的结果和真实结果做对比，提示有多少个数字和位置都正确的叫做bulls，还提示有多少数字正确但位置不对的叫做cows，根据这些信息来引导我们继续猜测正确的数字。这道题并没有让我们实现整个游戏，而只用实现一次比较即可。给出两个字符串，让我们找出分别几个bulls和cows。这题需要用哈希表，来建立数字和其出现次数的映射。我最开始想的方法是用两次遍历，第一次遍历找出所有位置相同且值相同的数字，即bulls，并且记录secret中不是bulls的数字出现的次数。然后第二次遍历我们针对guess中不是bulls的位置，如果在哈希表中存在，cows自增1，然后映射值减1，参见如下代码：

static void bullsandcows_I(string secret,string guess)
{
    int m[256];
    int bulls=0,cows=0;
    for(int i=0;i<secret.size();i++){
        if(secret[i]==guess[i]){
            bulls++;
        }else{
            m[secret[i]]++;
        }
    }
    for(int i=0;i<secret.size();i++){
        if(secret[i]!=guess[i] && m[guess[i]]){
            cows++;
            m[guess[i]]--;
        }
    }
    LC_LOGI("find! %d bulls, %d cows\n",bulls,cows);
    
}

static void bullsandcows_II(string secret,string guess)
{
    int m[256];
    int bulls=0,cows=0;
    for(int i=0;i<secret.size();i++){
        if(secret[i]==guess[i]){
            bulls++;
        }else{
            // secret和guess不是同一个的时候,记为cows
            if(m[secret[i]]++<0) cows++; // 之前就有guess做减了.
            if(m[guess[i]]-->0) cows++;
        }
    }
    LC_LOGI("find! %d bulls, %d cows\n",bulls,cows);
}


static void lc299__BullsandCows_case()
{
    string secret="1807";
    string guess="7810";
    bullsandcows_I(secret,guess);
    bullsandcows_II(secret,guess);
    
    
}

void lc_entry()
{
//    spiral_matrix_ii_case();
//    lc27__removeElements_case();
//    lc26__RemoveDuplicatesfromSortedArray_case();
//    lc80__RemoveDuplicatesfromSortedArray_II_case();
//    lc189__RotateArray_case();
//    lc41__FirstMissingPositive_case();
    lc299__BullsandCows_case();
}