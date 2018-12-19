#include "stdafx.h"
#include "algList.h"
#include <iostream>
using namespace std;


algList::algList()
{
}


algList::~algList()
{
}

static void question6_4()
{
	/*
	*例题6-4 破损的键盘（又名：悲剧文本）
	*（Broken Keyboard（a.k.a. Beiju Text）,UVa 11988）
	*
	* INPUT:
	* This_is_a_[Beiju]_text
	*
	* OUTPUT:
	* BeijuThis_is_a__text
	***/

#define MAX_LEN (1024)
	char s[MAX_LEN];
	int next[MAX_LEN];
	int cur, last;
	//std::cout << "hello" << std::endl;
	while (scanf_s("%s", s + 1, 1023) == 1) {
		int len = strlen(s + 1);
		cur = last = 0;
		next[0] = 0;
		if (strcmp(s + 1, "exit") == 0) {
			break;
		}
		/* YOUR CODE HERE */

		for (int i = 1; i <= len; i++) {
			if (s[i] == '[') cur = 0;
			else if (s[i] == ']') cur = last;
			else {
				next[i] = next[cur];
				next[cur] = i;
				if (cur == last)last = i;
				cur = i;
			}
		}
		for (int i = next[0]; i != 0; i = next[i]) {
			printf("%c", s[i]);

		}

	}
}
#define MAX_SIZE (1024)

int r[MAX_SIZE], l[MAX_SIZE];

static void link(int L, int R) {
	r[L] = R;
	l[R] = L;
}
static void question6_5()
{
	//例题6-5 移动盒子（Boxes in a Line, UVa 12657）
	//printf("hello 6-5\n");
	/* INPUT:
	 * 6 4
     * 1 1 4
     * 2 3 5
     * 3 1 6
	 * 4
	 * OUTPUT:
	 * 12
	 **/

	/* YOUR CODE HERE */
	
	int n, m, op = 0, inv=0,x,y;
	while (scanf_s("%d%d", &n, &m) == 2) {
		for (int i = 1; i <= n; i++) {
			r[i] = (i + 1) % (n + 1);
			l[i] = i - 1;
		}
		r[0] = 1;
		l[0] = n;

		while (m--) {
			scanf_s("%d", &op);
			if (op == 4) inv = !inv;
			else {
				scanf_s("%d%d", &x, &y);
				//if (op == 3 && r[y] == x) swap(x, y);
				if (op != 3 && inv)op = 3 - op;
				if (op == 1 && l[y] == x) continue;
				if (op == 2 && r[y] == x)continue;
				else {
					int LX = l[x], RX = r[x], LY = l[y], RY = r[y];
					if (op == 1) {
						link(LX, RX);
						link(LY, x);
						link(x, y);
					}
					else if (op == 2) {
						link(LX, RY);
						link(y, x);
						link(x, RY);
					}
					else if (op == 3) {
						if (r[x] == y) {
							link(LX, y);
							link(y, x);
							link(x, RY);
						}
#if 1
						else if (r[y] == x) {
							link(LY, x);
							link(x, y);
							link(y, RX);
						}
						else {
#else
						else {
#endif
							link(LX, y);
							link(y, RX);
							link(LY, x);
							link(x, RY);
						}
					}
				}

			}
		}
		long long ans = 0;
		int k = 0;
		for (int i = 1; i <= n; i++) {
			k = r[k];
			if (i % 2 == 1)
				ans += k;
		}
		if (inv && (n % 2 == 0))
			ans = (long long)n*(n + 1) / 2 - ans;

		printf("Case: %d", ans);

	}

}

BITEM bt_list[2] = {
	{0,"question 6-4",question6_4 },
	{1,"question 6-5",question6_5 },
};

void algList::action()
{
	printf("\n\ninput the `exit` will break the functions\n\n");
	for (int i = 0; i < sizeof(bt_list) / sizeof(BITEM); i++) {
		if (bt_list[i].enable) {
			printf("============================\n");
			printf("|| this is %s  ||\n", bt_list[i].name);
			printf("============================\n");
			bt_list[i].question();
		}
	}

}