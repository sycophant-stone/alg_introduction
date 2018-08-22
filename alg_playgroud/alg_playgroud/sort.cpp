#include "stdafx.h"
#include "sort.h"
#include <stdlib.h>
using namespace std;


sort::sort()
{
}


sort::~sort()
{
}


/*
 * ============================
 * || this is insert_sort  ||
 * ============================
 * 41 18467 6334 26500 19169 15724 11478 29358 26962 24464 5705 28145 23281 16827 9961 491 2995 11942 4827 5436
 * after sort
 * 41 491 2995 4827 5436 5705 6334 9961 11478 11942 15724 16827 18467 19169 23281 24464 26500 26962 28145 29358 请按任意键 继续. . .
 ***/
static void insert_sort()
{
#define MAX_LEN (20)
	int a[MAX_LEN];
	srand(1);
	for (int i = 0; i < MAX_LEN; i++) {
		a[i] = rand();
		printf("%d ", a[i]);
	}

	int key, j, i = 0;
	for (j = 1; j < MAX_LEN; j++) {
		i = j - 1;
		key = a[j];
		while (i > 0 && a[i] > key) {
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
	}
	printf("\nafter sort\n");
	for (int i = 0; i < MAX_LEN; i++) 
		printf("%d ", a[i]);
	
#ifdef MAX_LEN
#undef MAX_LEN
#endif
}



BITEM item_sort[5] = {
	{ 1,"insert_sort",insert_sort },
	//{ 0,"question 6-7",question6_7 },
	//{ 0,"question 6-8",question6_8 },
	//{ 0,"question 6-9",question6_9 },
	//{ 1,"question 6-9",question6_10 },
	////{ 1,"question 6-5",question6_5 },
};


void sort::action()
{
	printf("\n\ninput the `exit` will break the functions\n\n");
	for (int i = 0; i < sizeof(item_sort) / sizeof(BITEM); i++) {
		if (item_sort[i].enable) {
			printf("============================\n");
			printf("|| this is %s  ||\n", item_sort[i].name);
			printf("============================\n");
			item_sort[i].question();
		}
	}
	
}
