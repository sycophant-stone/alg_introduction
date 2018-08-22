#pragma once
typedef struct batch_item {
	int enable;
	char name[128];
	void(*question)(void);
}BITEM;