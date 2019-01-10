#include<iostream>
#include <map>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include<unordered_set>
#include <unordered_map>
#include <set>

using namespace std;
//#define OPEN_LOG
#ifdef OPEN_LOG
#define leet_logv printf
#define LC_LOGI(format,...) printf("[lc][%s]:[Line: %05d]: "format"\n", __FUNCTION__,__LINE__, ##__VA_ARGS__)  

#else
#define leet_logv 
//#define LC_LOGI
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
    //for(num:nums){
    for(int i=0;i<nums.size();i++){
        if(nums[i]<=0)
            continue;
        s.insert(nums[i]);
        mx=max(nums[i],mx);
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

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#134
// 我们首先要知道能走完整个环的前提是gas的总量要大于cost的总量，这样才会有起点的存在。假设开始设置起点start = 0, 并从这里出发，如果当前的gas值大于cost值，就可以继续前进，此时到下一个站点，剩余的gas加上当前的gas再减去cost，看是否大于0，若大于0，则继续前进。当到达某一站点时，若这个值小于0了，则说明从起点到这个点中间的任何一个点都不能作为起点，则把起点设为下一个点，继续遍历。当遍历完整个环时，当前保存的起点即为所求。

class GasStation{
    public:
    int gas_station(vector<int> &gas, vector<int> cost){
        int total=0, sum=0, start=0;
        printf("gas:\n");
        print_int_vector(gas);
        printf("cost:\n");
        print_int_vector(cost);
        for(int i=0;i<gas.size();i++){
            total+=gas[i]-cost[i]; // 跑完所有站的剩余量(可以为负值).
            sum+=gas[i]-cost[i];
            if(sum<0){ // 只能从下一站开始跑.
                start=i+1;
                sum=0;
            }
        }
        return (total < 0) ? -1 : start;
    }
};

static void lc134__GasStation_case()
{
    int start=0;
    vector<int> gas  = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    GasStation gass;
    start=gass.gas_station(gas,cost);
    LC_LOGI("find! start:%d\n",start);
    gas  = {2,3,4};
    cost = {3,4,3};
    start=gass.gas_station(gas,cost);
    LC_LOGI("find! start:%d\n",start);
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#118 pascal triangle
// 具体生成算是：每一行的首个和结尾一个数字都是1，从第三行开始，中间的每个数字都是上一行的左右两个数字之和。

class PacalTriangle{
    public:
    vector<vector<int>> generator(int numRows){
        vector<vector<int>> triangle(numRows,vector<int>());
        for(int i=0;i<numRows;i++){
            triangle[i].resize(i+1,1);  // 第i行有i+1个单位, 比如第0行有一个1, 第一行有2个1,1.
            for(int j=1;j<i;j++){
                triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];
            }
        }
        return triangle;
    }
    vector<int> generator_line(int rowid){
        vector<int> res(rowid+1); // 第rowid行 有 rowid个单元.
        res[0]=1;
        for(int i=1;i<=rowid;i++){
            for(int j=i;j>=1;j--){ // 从右边开始计算
                res[j]+=res[j-1]; //每次计算包括,上一行res[j-1]和本次res[j].
            }
        }
        return res;
    }
    
};

static void lc118__PascalTriangle_case()
{
    int numRows=5;
    vector<vector<int>> rest;
    PacalTriangle pscal;
    rest = pscal.generator(numRows);
    for(int i=0;i<numRows;i++){
        for(int j=0;j<i+1;j++){
            printf("%d ", rest[i][j]);
        }
        printf("\n");
    }

}
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#119 pascal triangle



static void lc119__PascalTriangel_II_case()
{
    int numRow=5;
    vector<int> ret;
    PacalTriangle pacal;
    ret=pacal.generator_line(numRow);
    for(int i=0;i<numRow+1;i++){
        printf("%d ",ret[i]);
    }
    printf("\n");
}
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#169 Majority Element
// 求众数. 超过一半的数.
// 用一种叫摩尔投票法 Moore Voting，需要O(n)的时间和O(1)的空间，比前一种方法更好。这种投票法先将第一个数字假设为众数，然后把计数器设为1，比较下一个数和此数是否相等，若相等则计数器加一，反之减一。然后看此时计数器的值，若为零，则将下一个值设为候选众数。以此类推直到遍历完整个数组，当前候选众数即为该数组的众数。
// 下面我们来看本算法的思路，这是一种先假设候选者，然后再进行验证的算法。我们现将数组中的第一个数假设为众数，然后进行统计其出现的次数，如果遇到同样的数，则计数器自增1，否则计数器自减1，如果计数器减到了0，则更换下一个数字为候选者。这是一个很巧妙的设定，也是本算法的精髓所在，为啥遇到不同的要计数器减1呢，为啥减到0了又要更换候选者呢？首先是有那个强大的前提存在，一定会有一个出现超过半数的数字存在，那么如果计数器减到0了话，说明目前不是候选者数字的个数已经跟候选者的出现个数相同了，那么这个候选者已经很weak，不一定能出现超过半数，我们选择更换当前的候选者。那有可能你会有疑问，那万一后面又大量的出现了之前的候选者怎么办，不需要担心，如果之前的候选者在后面大量出现的话，其又会重新变为候选者，直到最终验证成为正确的众数

class MajorityElement {
    public:
    int calc(vector<int> &nums){
        int cnt=0,res=0;
        //for(num:nums){ // 前提,肯定存在众数. 假定第一个为众数,然后验证.
        for(int i=0;i<nums.size();i++){
            if(cnt==0){ // 归零之后重新计算众数.
                res=nums[i]; 
                cnt++;
            }else if(nums[i]==res){
                cnt++; // 相同则增
            }else {
                cnt--; // 不同则减
            }
        }
        LC_LOGI("find! MajorityElement:%d\n",res);
        return res;
    }
    vector<int> calc_II(vector<int> &nums){
        vector<int> res;
        // Moore Voting
        int m=0,n=0,cntm=0,cntn=0;
        for(auto &a:nums){
            if(a==m){
                cntm++;
            }else if(a==n){
                cntn++;
            }else if(cntm==0){
                m=a;
            }else if(cntn==0){
                n=a;
            }else{
                cntm--;
                cntn--;
            }
        }
        // 因为最多有2个大于n/3的众数,所以需要验证是否是2个.
        cntm=cntn=0;
        for(auto &a:nums){
            if(a==m){
                cntm++;
            }else if(a==n){
                cntn++;
            }
        }
        
        if(cntm>nums.size()/3){
            
            res.push_back(m);
        }
        if(cntn>nums.size()/3){
            res.push_back(n);
        }
        return res;
    }
  
};

static void lc169__MajorityElement_case()
{
    vector<int> nums={2,2,1,1,1,2,2};
    MajorityElement me;
    me.calc(nums);
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#229 MajorityElement_II
// 这道题让我们求出现次数大于n/3的众数，而且限定了时间和空间复杂度，那么就不能排序，也不能使用哈希表，这么苛刻的限制条件只有一种方法能解了，那就是摩尔投票法 Moore Voting，这种方法在之前那道题Majority Element 求众数中也使用了。题目中给了一条很重要的提示，让我们先考虑可能会有多少个众数，经过举了很多例子分析得出，任意一个数组出现次数大于n/3的众数最多有两个，具体的证明我就不会了，我也不是数学专业的。那么有了这个信息，我们使用投票法的核心是找出两个候选众数进行投票，需要两遍遍历，第一遍历找出两个候选众数，第二遍遍历重新投票验证这两个候选众数是否为众数即可，选候选众数方法和前面那篇Majority Element 求众数一样，由于之前那题题目中限定了一定会有众数存在，故而省略了验证候选众数的步骤，这道题却没有这种限定，即满足要求的众数可能不存在，所以要有验证。

static void lc229__MajorityElement_II_case()
{
    vector<int> nums={1,1,1,3,3,2,2,2};
    vector<int> ret;
    MajorityElement me;
    ret=me.calc_II(nums);
    print_int_vector(ret);
}
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#274 H Index
// 这道题让我们求H指数，这个质数是用来衡量研究人员的学术水平的质数，定义为一个人的学术文章有n篇分别被引用了n次，那么H指数就是n。而且wiki上直接给出了算法，可以按照如下方法确定某人的H指数：1、将其发表的所有SCI论文按被引次数从高到低排序；2、从前往后查找排序后的列表，直到某篇论文的序号大于该论文被引次数。所得序号减一即为H指数。

class HIndex{
    public:
    int calc(vector<int> &citations){
        sort(citations.begin(),citations.end(),greater<int>());
        for(int i=0;i<citations.size();i++){
            if(i>=citations[i]){
                return i;
            }
        }
        return citations.size();
    }
    int calc_II(vector<int> &nums){
        // nums are sorted
        int left=0,right=nums.size()-1;
        int len=nums.size();
        while(left<right){
            int mid=0.5*(left+right);
            if(nums[mid]==len-mid){
                return len-mid;
            }else if(nums[mid]<len-mid){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return len-left;
    }
    
};

static void lc274__HIndex_case()
{
    vector<int> citations={3, 0, 6, 1, 5};
    HIndex hi;
    int ret=hi.calc(citations);
    LC_LOGI("find! H index:%d\n",ret);
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#275 H Index II
// 这题是之前那道H-Index 求H指数的拓展，输入数组是有序的，让我们在O(log n)的时间内完成计算，看到这个时间复杂度，应该有很敏锐的意识应该用二分查找法


static void lc275__HIndex_II_case()
{
    vector<int> citations={0,1,3,5,6};
    HIndex hi;
    int ret=hi.calc_II(citations);
    LC_LOGI("find! H index II:%d\n",ret);
}
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#243 Shortest Word Distance

class ShortestWordDistance{
    public:
    int generate(vector<string> nums,string word1, string word2){
        vector<int> wd1,wd2;
        int dstance=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==word1){
                wd1.push_back(i);
            }else if (nums[i]==word2){
                wd2.push_back(i);
            }
        }
        for(int i=0;i<wd1.size();i++){
            for(int j=0;j<wd2.size();j++){
                dstance= min(dstance,abs(wd1[i]-wd2[j]));
            }
        }
        return dstance;
    }
};
                             
static void lc243__ShortestWordDistance_case()
{
    vector<string> bagwords={"practice", "makes", "perfect", "coding", "makes"};
    ShortestWordDistance swd;
    int distance=swd.generate(bagwords,"coding","practice");
    LC_LOGI("find! distance:%d\n",distance);
    distance=swd.generate(bagwords,"makes","coding");
    LC_LOGI("find! distance:%d\n",distance);

}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#244 ShortestWordDistance_II
class WordDistance{
    public:
    WordDistance(vector<string> &words){
        for(int i=0;i<words.size();i++){
            m[words[i]].push_back(i); // string --> <pos1> <pos2> ...
        }
    }
    int calc_shortestdistance(string word1, string word2){
        int res=INT_MAX;
        for(int i=0;i<m[word1].size();i++){
            for(int j=0;j<m[word2].size();j++){
                res=min(res,abs(m[word1][i]-m[word2][j]));
            }
        }
        return res;
    }
    int calc_shortestdistance_opt(string word1,string word2){
        int res=INT_MAX;
        
    }
    private:
    unordered_map <string,vector<int>> m;
    
};

static void lc244__ShortestWordDistance_II_case()
{
    int res=-1;
    vector<string> bagwords={"practice", "makes", "perfect", "coding", "makes"};
    WordDistance wd(bagwords);
    res=wd.calc_shortestdistance("coding","practice");
    LC_LOGI("find! distance:%d\n",res);
}
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#245 ShortestWordDistance_III
// 这道题还是让我们求最短单词距离，有了之前两道题Shortest Word Distance II和Shortest Word Distance的基础，就大大降低了题目本身的难度。这道题增加了一个条件，就是说两个单词可能会相同，所以在第一题中的解法的基础上做一些修改. 
// 依次判断word1,word2的位置,对于word1和word2不同的情况,各自记录给子位置,然后就可以了.
// 对于word1和word2相同的情况,当找到word1时(其实也和word2值相同),对于word1的位置要更新成上个word2的位置,然后word2的的位置更新为此位置,这样做差了.

class WordDistanceSameWords{
    public:
    int shortestDistance(vector<string> bagswords,string word1,string word2){
        //int p1=-1,p2=-1;
        int p1=bagswords.size(),p2=-bagswords.size();// 初值很关键. 不然第一次,bagswords[0]都不是word1和word2. 这样这个min值就是0了,以后的值也不可能比这个值小了. 所以需要把abs(p1-p2)最大化,所以就有正负的bagswords的长度.
        int res=INT_MAX;
        for(int i=0;i<bagswords.size();i++){
            if(bagswords[i]==word1){
                p1=word1==word2?p2:i;
            }
            if(bagswords[i]==word2){
                p2=i;
            }
            res=min(res,abs(p1-p2));
        }
        return res;
    }
};

static void lc245__ShortestWordDistance_III_case()
{
    int ret=-1;
    vector<string> bagwords={"practice", "makes", "perfect", "coding", "makes"};
    WordDistanceSameWords wds;
    ret=wds.shortestDistance(bagwords,"makes","coding");
    LC_LOGI("find! distance:%d\n",ret);
    ret=wds.shortestDistance(bagwords,"makes","makes");
    LC_LOGI("find! distance:%d\n",ret);

}
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#217 Contain Duplicate
// 就是使用一个哈希表，遍历整个数组，如果哈希表里存在，返回false，如果不存在，则将其放入哈希表中

class ContainDuplicate{
    public:
    bool doJudge(vector<int> nums){
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){ // 当find函数找到时,会返回对应的iterator, 否则返回end()
                return true; //有重复的.
            }
            ++m[nums[i]];
        }
        return false;
    }
    bool JudgeNearlyK(vector<int> nums,int k){
        unordered_map<int,int> m;// val of nums[pos], pos
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()&&i-m[nums[i]]<=k){
                return true;// 对于某次值num[i],如果之前有值了,就判断两个重复值间距是否满足k.
            }
            else{
                m[nums[i]]=i; // val, pos
            }
        }
        return false;
    }
    bool JudgeIJ(vector<int> nums, int k , int t){
        map<long long, int> m; // val of nums, pos
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(i-j>k){
                // 更新j,使得i和j间距保持(不超过)k.
                m.erase(nums[j++]);
            }
            // 在m中找到第一个满足nums[i]-nums[j']<t的值.
            auto a=m.lower_bound((long long)nums[i]-t);
            if(a!=m.end()&&abs(a->first-nums[i])<=t){
                return true;
            }
            m[nums[i]]=i;
        }
        return false;
    }
};
    
static void lc217__ContainDuplicate_case()
{
    vector<int> exp1={1,2,3,1};
    vector<int> exp2={1,2,3,4};
    vector<int> exp3={1,1,1,3,3,4,3,2,4,2};
    bool ret=false;
    ContainDuplicate cd;
    ret=cd.doJudge(exp1);
    LC_LOGI("find! distance:%d\n",ret);
    ret=cd.doJudge(exp2);
    LC_LOGI("find! distance:%d\n",ret);
    ret=cd.doJudge(exp3);
    LC_LOGI("find! distance:%d\n",ret);
    
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#219 Contain Duplicate II
// 这道题是之前那道Contains Duplicate 包含重复值的延伸，不同之处在于那道题只要我们判断下数组中是否有重复值，而这道题限制了数组中只许有一组重复的数字，而且他们坐标差不能超过k


static void lc219__ContainDuplicates_II_case()
{
    vector<int> exp1={1,2,3,1}; //true
    vector<int> exp2={1,0,1,1}; //true
    vector<int> exp3={1,2,3,1,2,3}; //false
    int k1=3,k2=1,k3=2;
    bool ret=false;
    ContainDuplicate cd;
    ret=cd.JudgeNearlyK(exp1,k1);
    LC_LOGI("find! JudgeNearlyK:%d\n",ret);
    ret=cd.JudgeNearlyK(exp2,k2);
    LC_LOGI("find! JudgeNearlyK:%d\n",ret);
    ret=cd.JudgeNearlyK(exp3,k3);
    LC_LOGI("find! JudgeNearlyK:%d\n",ret);
    
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#220 Contain Duplicate III
    
static void lc220__ContainDuplicate_III_case()
{
    vector<int> exp1={1,2,3,1}; //true
    vector<int> exp2={1,0,1,1}; //true
    vector<int> exp3={1,5,9,1,5,9}; //false
    int k1=3,k2=1,k3=2;
    int t1=0,t2=2,t3=3;
    bool ret=false;
    ContainDuplicate cd;
    ret=cd.JudgeIJ(exp1,k1,t1);
    LC_LOGI("find! JudgeIJ:%d\n",ret);
    ret=cd.JudgeIJ(exp2,k2,t2);
    LC_LOGI("find! JudgeIJ:%d\n",ret);
    ret=cd.JudgeIJ(exp3,k3,t3);
    LC_LOGI("find! JudgeIJ:%d\n",ret);

}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#55 Jump Game
// 这道题说的是有一个非负整数的数组，每个数字表示在当前位置的基础上最多可以走的步数，求判断能不能到达最后一个位置，开始我以为是必须刚好到达最后一个位置，超过了不算，其实是理解题意有误，因为每个位置上的数字表示的是最多可以走的步数而不是像玩大富翁一样摇骰子摇出几一定要走几步。那么我们可以用动态规划Dynamic Programming来解，我们维护一个一位数组dp，其中dp[i]表示达到i位置时剩余的步数，那么难点就是推导状态转移方程啦。
// 到达当前位置的剩余步数跟什么有关呢，其实是跟上一个位置的剩余步数和上一个位置的跳力有关，这里的跳力就是原数组中每个位置的数字，因为其代表了以当前位置为起点能到达的最远位置。
// 所以当前位置的剩余步数（dp值）和当前位置的跳力中的较大那个数决定了当前能到的最远距离，而下一个位置的剩余步数（dp值）就等于当前的这个较大值减去1，因为需要花一个跳力到达下一个位置
// 状态转移方程了：dp[i] = max(dp[i - 1], nums[i - 1]) - 1
// 如果当某一个时刻dp数组的值为负了，说明无法抵达当前位置，则直接返回false，最后我们判断dp数组最后一位是否为非负数即可知道是否能抵达该位置

class JumpGame{
    public:
    bool jumpEnd(vector<int> nums){
        vector<int> dp(nums.size(),0); // 初始化dp为零值.
        for(int i=1;i<nums.size();i++){
            dp[i]=max(dp[i-1],nums[i-1])-1;
            if(dp[i]<0){
                return false;
            }
        }
        return dp.back()>=0;// 最后一个元素的引用,其值是否为正.
    }
    bool greedyjumpEnd(vector<int> nums){
        int reach=0;
        for(int i=0;i<nums.size();i++){
            if(reach<i||reach>(nums.size()-1))
                break;
            reach=max(reach,i+nums[i]); // 更新reach.
        }
        return reach >=(nums.size()-1);
    }
    int leastStepJumpEnd(vector<int> nums){
        int stepcnt=0,cur=0,i=0;
        while(cur<nums.size()-1){
            stepcnt++;
            int pre=cur;
            for(;i<=pre;i++){ // 注意此处有个等于
                cur=max(cur,i+nums[i]);
            }
        }
        return stepcnt;
    }
};

static void lc55_JumpGame_case()
{
    vector<int> exp1={2,3,1,1,4}; // ture
    vector<int> exp2={3,2,1,0,4}; // false
    JumpGame jg;
    bool ret=false;
    ret=jg.jumpEnd(exp1);
    LC_LOGI("find! jumpEnd:%d\n",ret);
    ret=jg.jumpEnd(exp2);
    LC_LOGI("find! jumpEnd:%d\n",ret);
    ret=jg.greedyjumpEnd(exp1);
    LC_LOGI("find! greedyjumpEnd:%d\n",ret);
    ret=jg.greedyjumpEnd(exp2);
    LC_LOGI("find! greedyjumpEnd:%d\n",ret);

}
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#45 Jump Game II
// 此题只让我们求到达最后一个位置的最少跳跃数
// 需要两个变量cur和pre分别来保存当前的能到达的最远位置和之前能到达的最远位置，只要cur未达到最后一个位置则循环继续
// 遍历当前跳跃能到的所有位置，算出一个最远的范围

static void lc45_JumpGame_II_case()
{
    vector<int> exp1={2,3,1,1,4}; // 2.
    JumpGame jg;
    int ret=-1;
    ret=jg.leastStepJumpEnd(exp1);
    LC_LOGI("find! leastStepJumpEnd steps:%d\n",ret);
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#121 Best Time To Buy And Sell Stock

class Stock{
    public:
    int whentobuyandSell(vector<int> stock){
        int res=0,buy=INT_MAX;
        for(int i=0;i<stock.size();i++){
            buy=min(buy,stock[i]);
            res=max(res,stock[i]-buy);
        }
        return res;
    }
    int whentobuyandSell_II(vector<int> stock){
        int res=0;
        for(int i=0;i<stock.size()-1;i++){
            if(stock[i+1]>stock[i]){
                res+=stock[i+1] - stock[i];
            }
        }
        return res;
    }
    int whenToBuyAndSell_III(vector<int> stock){
        if(stock.empty()) return 0;
        int global[3] = {0}, local[3] = {0}; // 3是代表第2次.
        for(int i=0;i<stock.size()-1;i++){ // 遍历天数,计算差值
            int diff = stock[i+1] - stock[i];
            for(int j=2;j>=1;j--){
                local[j] = max(global[j-1]+max(diff,0), local[j]+diff);
                global[j] = max(local[j],global[j]); // global基于local
            }
        }
        return global[2];
        
    }
    int whenToBuyAndSell_IV(vector<int> stock,int k){
        if(stock.empty()) return 0;
        if(k>=stock.size()) return whentobuyandSell_II(stock);
        int global[k+1] = {0}, local[k+1] = {0};
        for(int i=0;i<stock.size()-1;i++){
            int diff=stock[i+1] - stock[i];
            for(int j=k;j>=1;j--){
                local[j] = max(global[j-1]+max(diff,0), local[j]+diff);
                global[j] = max(global[j],local[j]);
            }
        }
        return global[k];
    }
    int whenToBuyAndSell_With_CoolDown(vector<int> stock){
        int buy=INT_MIN,pre_buy=0,sell=0,pre_sell=0;
        for(int i=0;i<stock.size();i++){
            pre_buy=buy;
            buy = max(pre_buy, sell-stock[i]);
            pre_sell=sell;
            sell=max(pre_sell,pre_buy+stock[i]);
        }
        return sell;
    }
};

static void lc121__BestTimeToBuyAndSellStock_case()
{
    vector<int> exp1={7,1,5,3,6,4}; //5
    vector<int> exp2={7,6,4,3,1}; //0
    int ret=-1;
    Stock stk;
    ret=stk.whentobuyandSell(exp1);
    LC_LOGI("find! whentobuyandSell' price :%d\n",ret);
    ret=stk.whentobuyandSell(exp2);
    LC_LOGI("find! whentobuyandSell' price :%d\n",ret);

}


static void lc122__BestTimeToBuyAndSellStock_II_case()
{
    vector<int> exp1={7,1,5,3,6,4}; //7
    vector<int> exp2={1,2,3,4,5}; //4
    vector<int> exp3={7,6,4,3,1}; //0
    int ret=-1;
    Stock stk;
    ret=stk.whentobuyandSell_II(exp1);
    LC_LOGI("find! whentobuyandSell_II' price :%d\n",ret);
    ret=stk.whentobuyandSell_II(exp2);
    LC_LOGI("find! whentobuyandSell_II' price :%d\n",ret);
    ret=stk.whentobuyandSell_II(exp3);
    LC_LOGI("find! whentobuyandSell_II' price :%d\n",ret);

}
static void lc123__BestTimeToBuyAndSellStock_III_case()
{
    vector<int> exp1={3,3,5,0,0,3,1,4}; // 6
    vector<int> exp2={1,2,3,4,5}; // 4
    vector<int> exp3={7,6,4,3,1}; // 0
    int ret = -1;
    Stock stk;
    ret=stk.whenToBuyAndSell_III(exp1);
    LC_LOGI("find! whenToBuyAndSell_III' price :%d\n",ret);
    ret=stk.whenToBuyAndSell_III(exp2);
    LC_LOGI("find! whenToBuyAndSell_III' price :%d\n",ret);
    ret=stk.whenToBuyAndSell_III(exp3);
    LC_LOGI("find! whenToBuyAndSell_III' price :%d\n",ret);    
}
static void lc188__BestTimeToBuyAndSellStock_IV_case()
{
    vector<int> exp1={2,4,1}; // 2
    vector<int> exp2={3,2,6,5,0,3}; // 7
    int k1 = 2;
    int k2 = 2;
    int ret = -1;
    Stock stk;
    ret=stk.whenToBuyAndSell_IV(exp1,k1);
    LC_LOGI("find! whenToBuyAndSell_IV' price :%d\n",ret);
    ret=stk.whenToBuyAndSell_IV(exp2,k2);
    LC_LOGI("find! whenToBuyAndSell_IV' price :%d\n",ret);
}

static void lc309__BestTimeToBuyAndSellStockWithCOOLDOWN_case()
{
    vector<int> exp1={1, 2, 3, 0, 2}; // 3
    int ret = -1;
    Stock stk;
    ret = stk.whenToBuyAndSell_With_CoolDown(exp1);
    LC_LOGI("find! whenToBuyAndSell_With_CoolDown' price :%d\n",ret);
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#11 Container With Most Water 

class Container{
    public:
    int MostWater(vector<int> nums){
        int i=0;
        int j=nums.size()-1;
        int res = INT_MIN;
        while(i<j){
            res =max(res, (j-i)*(min(nums[i],nums[j])));
            nums[i]<nums[j]?i++:j--;
        }
        return res;
    }
};
static void lc11_ContainerWithMostWater_case()
{
    vector<int> exp1={1,8,6,2,5,4,8,3,7}; // 49
    int ret = INT_MIN;
    Container ctr;
    ret = ctr.MostWater(exp1);
    LC_LOGI("find! MostWater:%d\n",ret);
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#11 lc42__TrappingRainWater_case

class TrapRainWater{
    public:
    int collectWater(vector<int> water){
        int l=0,r=water.size()-1,res=0;
        int lmax=0,rmax=0;
        while(l<r){
            if(water[l]<water[r]){
                lmax = water[l++];// 这里的更新,不然下面的lmax>water[l]肯定是不成立的,导致l不会++.
                while(l<r&&lmax>water[l]){
                    res+=lmax-water[l];
                    l++;
                }
            }else{
                rmax=water[r--];
                while(l<r&&rmax>water[r]){
                    res+=rmax-water[r];
                    r--;
                }
            }
        }
        return res;
        
    }
};
static void lc42__TrappingRainWater_case()
{
    vector<int> exp1={0,1,0,2,1,0,1,3,2,1,2,1}; // 6
    int ret=INT_MIN;
    TrapRainWater trw;
    ret = trw.collectWater(exp1);
    LC_LOGI("find! TrappingRainWater:%d\n",ret);
}
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#334 lc334__IncreasingTripletSubsequence_case

class TripletSubsequence{
    public:
    bool increasingTriplet(vector<int> nums){
        vector<int> dp(nums.size(),1); // n个单位,初始值为1.
        int breakpoint = 3;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i] = max(dp[i],dp[i-1]+1);
                    if(dp[i]>breakpoint)
                        return true;
                }
            }
            
        }
        return false;
    }
};


static void lc334__IncreasingTripletSubsequence_case()
{
    vector<int> exp1={1, 2, 3, 4, 5};// true
    vector<int> exp2={5, 4, 3, 2, 1};// false
    int ret=0;
    TripletSubsequence ts;
    ret = ts.increasingTriplet(exp1);
    LC_LOGI("find! increasingTriplet:%d\n",ret);
    ret = ts.increasingTriplet(exp2);
    LC_LOGI("find! increasingTriplet:%d\n",ret);

}
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#128 lc128__LongestConsecutiveSequence_case
// 100, 4, 200, 1, 3, 2
// 找到无序数组中"连续个数",100, 4, 200, 1, 3, 2中可以找到1,2,3,4共四个连续的数.
class ConsecutiveSequence{
    public:
    int LongestOne(vector<int> nums){
        int res=INT_MIN;
        unordered_set<int> s(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(!s.count(nums[i]))continue;
            s.erase(nums[i]);//删除
            int pre=nums[i]-1;
            int next=nums[i]+1;
            while(s.count(pre))s.erase(pre--);
            while(s.count(next))s.erase(next++);
            res=max(res,next-pre-1);
        }
        return res;
    }
};
static void lc128__LongestConsecutiveSequence_case()
{
    vector<int> exp1={100, 4, 200, 1, 3, 2};//4
    int ret=0;
    ConsecutiveSequence cs;
    ret = cs.LongestOne(exp1);
    LC_LOGI("find! LongestOne:%d\n",ret);
}
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#64 lc164__MaximumGap_case
class Gap{
    public:
    int maximum(vector<int> nums){
        // 桶排序思想,拿到最大最小值.
        int mn=INT_MAX,mx=INT_MIN;
        int res=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mn=min(mn,nums[i]);
            mx=max(mx,nums[i]);
        }
        int bucket_size = (mx-mn)/nums.size() + 1; // 拿到桶个数,每个桶装多少.
        int bucket_num = (mx-mn)/bucket_size + 1;
        std::set<int> s;
        vector<int> bucket_min(bucket_num,INT_MAX);
        vector<int> bucket_max(bucket_num,INT_MIN);
        for(int i=0;i<nums.size();i++){
            int idx = (nums[i]-mn)/bucket_size; // 给每个数找到自己桶.
            bucket_min[idx] = min(bucket_min[idx],nums[i]);
            bucket_max[idx] = max(bucket_max[idx],nums[i]);
            s.insert(idx);
        }
        int pre=0;
        for(int i=0;i<nums.size();i++){
            if(!s.count(i))continue;
            res=max(res,bucket_min[i]-bucket_max[pre]); // 因为我们桶的个数和nums成员个数一样,所以桶间的差才是gap.
            pre=i;
        }
        
        return res;
    }
};
static void lc164__MaximumGap_case()
{
    vector<int> exp1={3,6,9,1};// 3
    int ret=0;
    Gap gap;
    ret = gap.maximum(exp1);
    LC_LOGI("find! maximun:%d\n",ret);
    
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#287 lc287__FindtheDuplicateNumber_case
class DuplicateNumber{
    public:
    int findfirst(string words){
        unordered_map<char,int> m;
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }
        for(int i=0;i<words.size();i++){
            if(m[words[i]]==1)
                return i;
        }
        return -1;
    }
};
static void lc287__FindtheDuplicateNumber_case()
{
    string exp1 = "leetcode";//0
    string exp2 = "loveleetcode";//2
    int ret=0;
    
    DuplicateNumber dn;
    ret = dn.findfirst(exp1);
    LC_LOGI("find!findfirst DuplicateNumber:%d\n",ret);
    ret = dn.findfirst(exp2);
    LC_LOGI("find!findfirst DuplicateNumber:%d\n",ret);

}
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
// lc#145 lc145__Candy_case
class Candy{
    public:
    int minCandies(vector<int> rating){
        //两次遍历.
        int res=0;
        vector<int> cds(rating.size(),1);
        for(int i=0;i<rating.size()-1;i++){
            if(rating[i+1]>rating[i])
                cds[i+1]=cds[i]+1;
        }
        for(int i=rating.size()-1;i>0;i--){
            if(rating[i-1]>rating[i]){
                cds[i-1] = max(cds[i-1],cds[i]+1);
            }
        }
        for(int i=0;i<cds.size();i++){
            res+=cds[i];
        }
        return res;
    }
};
static void lc145__Candy_case()
{
    vector<int> exp1={1,0,2};//5
    vector<int> exp2={1,2,2};//4
    int ret=0;
    Candy cd;
    ret = cd.minCandies(exp1);
    LC_LOGI("find!minCandies :%d\n",ret);
    ret = cd.minCandies(exp2);
    LC_LOGI("find!minCandies :%d\n",ret);
    
}
void lc_entry()
{
//    spiral_matrix_ii_case();
//    lc27__removeElements_case();
//    lc26__RemoveDuplicatesfromSortedArray_case();
//    lc80__RemoveDuplicatesfromSortedArray_II_case();
//    lc189__RotateArray_case();
//    lc41__FirstMissingPositive_case();
//    lc299__BullsandCows_case();
//    lc134__GasStation_case();
//    lc118__PascalTriangle_case();
//    lc119__PascalTriangel_II_case();
//    lc169__MajorityElement_case();
//    lc229__MajorityElement_II_case();
//    lc274__HIndex_case();
//    lc275__HIndex_II_case();
//    lc243__ShortestWordDistance_case();
//    lc244__ShortestWordDistance_II_case();
//    lc245__ShortestWordDistance_III_case();
//    lc217__ContainDuplicate_case();
//    lc219__ContainDuplicates_II_case();
//    lc220__ContainDuplicate_III_case();
//    lc55_JumpGame_case();
//    lc45_JumpGame_II_case();
//    lc121__BestTimeToBuyAndSellStock_case();
//    lc122__BestTimeToBuyAndSellStock_II_case();
//    lc123__BestTimeToBuyAndSellStock_III_case();
//    lc188__BestTimeToBuyAndSellStock_IV_case();
//    lc309__BestTimeToBuyAndSellStockWithCOOLDOWN_case();
//    lc11_ContainerWithMostWater_case();
//    lc42__TrappingRainWater_case();
//    lc334__IncreasingTripletSubsequence_case();
//    lc128__LongestConsecutiveSequence_case();
//    lc164__MaximumGap_case();
//    lc287__FindtheDuplicateNumber_case();
    lc145__Candy_case();
}