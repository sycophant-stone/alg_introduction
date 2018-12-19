#include<iostream>
#include <map>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include<unordered_set>

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
        for(num:nums){ // 前提,肯定存在众数. 假定第一个为众数,然后验证.
            if(cnt==0){ // 归零之后重新计算众数.
                res=num; 
                cnt++;
            }else if(num==res){
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
    lc243__ShortestWordDistance_case();
}