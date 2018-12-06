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



void leet_question_array()
{
    cout<<"leet_question1"<<endl;
    spiral_matrix_ii(3);
    spiral_matrix_ii(4);
    spiral_matrix_ii(5);
}

void lc_entry()
{
    spiral_matrix_ii(3);
}