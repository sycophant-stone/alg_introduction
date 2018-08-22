#include "stdafx.h"
#include "string.h"
#include "algTree.h"
#include <vector>
#include <queue>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

algTree::algTree()
{
}


algTree::~algTree()
{
}
struct Node {
	int val;
	bool has_init;
	struct Node *left;
	struct Node *right;
	Node() :has_init(false), left(NULL), right(NULL) {}
};
struct Node *root;
static char s[1024];
static bool failed;
static void addnode(int val, char *s) {
	struct Node *u;
	u = root;
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (s[i] == 'L') {
			if (!u->left) u->left = new Node();
			u = u->left;
		}else if (s[i] == 'R') {
			if (!u->right) u->right = new Node();
			u = u->right;
		}
	}
	if (u->has_init) {
		failed = true;
		return;
	}
	u->val = val;
	u->has_init = true;
	
}
static bool input() {
	failed = false;
	root = new Node();
	while (scanf_s("%s", &s, 1024) == 1) {
		if (!strcmp(s, "()"))break;
		int val;
		sscanf_s(&s[1], "%d", &val);
		addnode(val, strchr(s, ',') + 1);
	}
	return true;
}
bool bfs(vector<int>& ans)
{
	queue<Node*> q;
	ans.clear();
	q.push(root);
	while (!q.empty()) {
		struct Node *u = q.front(); q.pop();
		if (!u->has_init)return false;
		ans.push_back(u->val);
		if (u->left)q.push(u->left);
		if (u->right)q.push(u->right);
	}
	return true;
}
static void remove_tree(struct Node *u)
{
	if (u->left)remove_tree(u->left);
	if (u->right)remove_tree(u->right);
	delete u;
}
/*
* INPUT: (11,LL) (7,LLL) (8,R) (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
* OUTPUT: 5 4 8 11 13 4 7 2 1
***/
static void question6_7()
{
	bool ret;
	vector<int> ans;
	ret = input();
	if (ret == false) {
		printf("error\n");
		return;
	}
	ret = bfs(ans);
	if (ret == false) {
		printf("error\n");
		return;
	}
	for (auto it = ans.begin(); it != ans.end(); ++it) {
		printf("%d ", *it);
	}
	remove_tree(root);
}


static void question6_6() 
{
	int D, I;
#define MAX_TREE_DEPTH (20)
	int s[MAX_TREE_DEPTH];
	memset(s, 0, sizeof(s));
	int k;
	while (scanf_s("%d%d", &D, &I) == 2) {
		for (int i = 1; i <= I; i++) {
			k = 1;
			while (1) {
				s[k] = !s[k];
				k = s[k] ? (2 * k) : (2 * k + 1);
				if (k > ((1 << D) - 1))break;
			}
		}
		printf("%d", k / 2);
	}

}
static int in_order[1000], post_order[1000], lch[1000], rch[1000];
static int n_tree;
static bool readline(int *a) 
{
	string line;
	if (!getline(cin, line)) return false;
	stringstream ss(line);
	int x;
	n_tree = 0;//注意这个要使用两次,中序遍历和后序遍历都要使用.
	while (ss >> x) a[n_tree++] = x;
	return n_tree > 0;
}
static int build(int l1, int r1, int l2, int r2) 
{
#if 0
	if (l1 > r1)return 0; // 结束它条件
	int root = post_order[r2];
	int pos = l1;//第一次可能是从0开始,但之后就不一定是0了.
	while (in_order[pos] != root) pos++;//更新pos
	int cnt = pos - l1;
	//printf("root:%d,l1:%d,r1:%d,l2:%d,r2:%d,pos:%d,cnt:%d\n", root, l1, r1, l2, r2, pos, cnt);
	lch[root] = build(l1, pos - 1, l2, l2 + cnt - 1);
	rch[root] = build(pos + 1, r1, l2 + cnt, r2 - 1);
	return root;
#endif
	if (l1 > r1)return 0;
	int root = post_order[r2];
	int pos = l1;
	while (in_order[pos] != root)pos++;
	int cnt = pos - l1;
	lch[root] = build(l1, pos - 1, l2, l2 + cnt - 1);
	rch[root] = build(pos + 1, r1, l2 + cnt, r2 - 1);
	return root;
}
static int best_node, best_sum;
static void dfs(int u, int sum) {
	sum += u;
	if (!lch[u] && !rch[u]) {
		if ((sum < best_sum)||(sum==best_sum&&u<best_node)) {
			best_sum = sum;
			best_node = u;
		}
	}
	if (lch[u]) dfs(lch[u], sum);
	if (rch[u])dfs(rch[u], sum);
}
static void question6_8() {
	while (readline(in_order)) {
		readline(post_order);
		build(0, n_tree - 1, 0, n_tree - 1);
		best_sum = 100000;
		dfs(post_order[n_tree - 1], 0);
		printf("best:%d\n", best_node);
	}
}
static bool solve(int &w)
{
	int w1, w2, d1, d2;
	bool b1 = true, b2 = true;
	cin >> w1 >> d1 >> w2 >> d2;
	if (!w1)b1 = solve(w1);
	if (!w2)b2 = solve(w2);
	w = w1 + w2;
	return b1&&b2 && (w1*d1 == w2*d2);
}
static void question6_9()
{
	int T, W;
	cin >> T;
	while (T--) {
		solve(W) ? printf("Yes") : printf("No");
	}
}
#define MAX_SUM_ITEM (1000)
static int sum[MAX_SUM_ITEM];
static void create(int pos)
{
	int x;
	cin >> x;
	if (x == -1)return;
	sum[pos] += x;
	create(pos - 1);
	create(pos + 1);
}
static bool init()
{
	int x, pos = MAX_SUM_ITEM / 2;
	cin >> x;
	sum[pos] = x;
	create(pos - 1);
	create(pos + 1);
	return 0;
}
/*
 * 样例输入：
 * 5 7 -1 6 -1 -1 3 -1 -1
 * 8 2 9 -1 -1 6 5 -1 -1 12 -1 -1 3 7 -1 -1 -1 -1
 * 样例输出：
 * Case 1:
 * 7 11 3
 * Case 2:
 * 9 7 21 15
 ***/
static void question6_10(void)
{
	memset(sum, 0, sizeof(sum));
	init();
	for (int i = 0; i < MAX_SUM_ITEM; i++) {
		if (sum[i] != 0) {
			printf("%d ", sum[i]);
		}
	}
	printf("\n");
}
BITEM bt_tree[5] = {
	{ 0,"question 6-6",question6_6 },
	{ 0,"question 6-7",question6_7 },
	{ 0,"question 6-8",question6_8 },
	{ 0,"question 6-9",question6_9 },
	{ 1,"question 6-10",question6_10 },
	//{ 1,"question 6-5",question6_5 },
};

void algTree::action()
{
	printf("\n\ninput the `exit` will break the functions\n\n");
	for (int i = 0; i < sizeof(bt_tree) / sizeof(BITEM); i++) {
		if (bt_tree[i].enable) {
			printf("============================\n");
			printf("|| this is %s  ||\n", bt_tree[i].name);
			printf("============================\n");
			bt_tree[i].question();
		}
	}

}


