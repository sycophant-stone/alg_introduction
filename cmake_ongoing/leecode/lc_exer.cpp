#include<iostream>
#include <map>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;
#define OPEN_LOG
#ifdef OPEN_LOG
#define leet_logv printf
#define LC_LOGI(format,...) printf("[lc][Line: %05d]: "format"\n", __LINE__, ##__VA_ARGS__)  
#else
#define leet_logv 
#define LC_LOGI
#endif
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


void lc_entry()
{
//    spiral_matrix_ii_case();
//    lc27__removeElements_case();
    lc26__RemoveDuplicatesfromSortedArray_case();
}