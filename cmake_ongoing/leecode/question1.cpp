#include<iostream>
#include <map>
#include <string.h>
using namespace std;
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

void leet_question_array()
{
    cout<<"leet_question1"<<endl;
    //test_two_sum();
}
