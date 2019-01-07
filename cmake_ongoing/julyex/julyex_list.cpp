#include<iostream>
#include <malloc.h>
using namespace std;

//#define JULY_LOGI(format,...) printf("File: "__FILE__", Line: %05d: "format"\n", __LINE__, ##__VA_ARGS__)  
//#define JULY_LOGI(format,...) printf("[Line: %05d]: "format"\n", __LINE__, ##__VA_ARGS__)  
#define JULY_LOGI(format,...) 
 
//定义一个链表节点
struct ListNode
{
	int value;
	ListNode *next;
    ListNode *random;
};
 
//插入一个新节点到链表中(放在链表头部)
void CreateList(ListNode * & head, int data)
{
	//创建新节点
	ListNode * p = (ListNode*)malloc(sizeof(ListNode));
	p->value = data;
	p->next = NULL;
 
	if (head == NULL)
	{
		head = p;
		return;
	}
	p->next = head;
	head = p;
}
 
void  printList(ListNode* head)
{
	ListNode * p = head;
	while (p != NULL)
	{
		cout << p->value<< " ";
		p = p->next;
	}
	cout << endl;
}
 
 
//递归方式：实现单链表反转
ListNode * ReverseList(ListNode * head)
{
	//递归终止条件：找到链表最后一个结点
	if (head == NULL || head->next == NULL)
		return head;
	else
	{
		ListNode * newhead = ReverseList(head->next);//先反转后面的链表，从最后面的两个结点开始反转，依次向前
		head->next->next = head;//将后一个链表结点指向前一个结点
		head->next = NULL;//将原链表中前一个结点指向后一个结点的指向关系断开
		return newhead;
	}
}
 
//非递归方式：实现单链表反转
ListNode* reverseList2(ListNode* head) {
	if (head == NULL || head->next == NULL) 
		return head;
	ListNode* prev = head;
	ListNode* cur = head->next;
	ListNode* temp = head->next->next;
 
	while (cur){
		temp = cur->next; //temp作为中间节点，记录当前结点的下一个节点的位置
		cur->next = prev;  //当前结点指向前一个节点
		prev = cur;     //指针后移
		cur = temp;  //指针后移，处理下一个节点
	}
 
	head->next = NULL; //while结束后，将翻转后的最后一个节点（即翻转前的第一个结点head）的链域置为NULL
	return prev;
}
 
static void list_reverse_case()
{
	ListNode * head = NULL;
	for (int i = 0; i<9; i++)
		CreateList(head, i);
	printList(head);
	head = ReverseList(head);
	printList(head);
	//system("pause");
    
}
//http://www.cppblog.com/yuech/archive/2011/04/02/143318.html
static struct ListNode* list_copy(struct ListNode* head)
{
    struct ListNode *newhead=NULL;//显示的赋值为NULL才可以.
    struct ListNode *temp=head,*newtemp=NULL;
    newtemp=newhead;
    if(newhead!=NULL)
        JULY_LOGI("newhead:%p\n",newhead);
    if(temp==NULL)
        JULY_LOGI("input head is NULL\n");
    while(temp!=NULL){
        ListNode * newtemp = (ListNode*)malloc(sizeof(ListNode));
        if(newhead==NULL){
            JULY_LOGI("[newhead] the first newhead is NULL\n");
            newhead=newtemp;
            JULY_LOGI("[newhead] :%p ,newtemp:%p\n",newhead,newtemp);
        }
        newtemp->next=temp->next;
        temp->next=newtemp;
        newtemp->value=temp->value;
        JULY_LOGI("[list_copy]: temp->value:%d, newtemp->value:%d,temp:%p,newtemp:%p,newtemp->value:%d\n",temp->value,newtemp->value,temp,newtemp,newtemp->value);
        temp=newtemp->next;
    }
    JULY_LOGI("print new head:%p\n",newhead);//问题点
    JULY_LOGI("print head(%p):\n",newhead);//问题点
    printList(head);
    JULY_LOGI("copy random parts\n");
    temp=head;
    newtemp=newhead;
    while(temp!=NULL){
        JULY_LOGI("[list_copy]: temp(%p)->value:%d,newtemp(%p)->value:%d\n",temp,temp->value,newtemp,newtemp->value);
        if(temp->random){
            newtemp->random=temp->random->next;
            JULY_LOGI("[list_copy]: temp->random->next(%p):%d, newtemp(%p)->value:%d,newtemp->random(%p)\n",temp->random->next,temp->random->next->value,newtemp,newtemp->value,newtemp->random);
        }
        if(newtemp->next)// 不然会有段错误.
            temp=newtemp->next;
        else
            break;// 退出条件
        if(temp->next)
            newtemp=temp->next;
    }
    temp=head;
    newtemp=newhead;
    while(temp!=NULL){
        JULY_LOGI("[list_copy]: temp(%p)->value:%d\n",temp,temp->value);
        temp->next=newtemp->next;
        if(newtemp->next)
            temp=newtemp->next;
        else
            break;
        if(temp->next)
            newtemp=temp->next;
    }
    return newhead;
}

static void list_copy_case()
{
    ListNode * head = NULL;
    ListNode * temp = NULL;
	for (int i = 0; i<9; i++)
		CreateList(head, i);
	printList(head);
    // create random
    temp=head;
    for (int i=0;i<9;i++){
        if(i%3==0){
            temp->random=temp->next->next;
            //JULY_LOGI("i:%d, temp:%d, temp->next->next:%d\n",i,temp->value,temp->next->next->value);
        }
        temp=temp->next;
    }
    temp = head;
	while (temp!=NULL)	{
        if(temp->random != NULL)
            JULY_LOGI("%d node randomly to %d'node\n",temp->value,temp->random->value);
		temp = temp->next;
	}  
    
    ListNode * newlist=list_copy(head);
    printList(newlist);
    temp=newlist;
    while (temp!=NULL)	{
        if(temp->random != NULL)
            JULY_LOGI("%d node randomly to %d'node\n",temp->value,temp->random->value);
		temp = temp->next;
	}  
    
}
int julyex_list_entry()
{
    //list_reverse_case();
    //list_copy_case();
	return 0;
}

