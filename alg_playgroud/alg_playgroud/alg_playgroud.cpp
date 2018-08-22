// alg_playgroud.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "algList.h"
#include "algTree.h"
#include "algbase.h"
#include "sort.h"
#include "CONFIG.h"
int main()
{
#if 0
	class algList localA;
	localA.action();
#endif
#if 0
	class algTree localTree;
	localTree.action();
#endif

#ifdef ALG_SORT
	class sort localsort;
	localsort.action();
#endif

	return 0;
}

