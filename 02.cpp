#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
}*PNode;

//struct ListNode* creatList1() {
//	struct ListNode *p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	p1->val = 2;
//	p1->next->val = 4;      //这么写是不对的，应该要先创建一个新的节点，然后再赋值。。
//	p1->next->next->val = 3;
//	p1->next->next->next = NULL;
//	return p1;
//}
struct ListNode* creatList1() {
	struct ListNode *p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	p1->next = NULL;
	struct ListNode *ptail = p1;
	int A[] = { 2,4,3 };
	int i;
	for (i = 0; i < 3; i++) {
		struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		newNode->val = A[i];
		newNode->next = NULL;
		ptail->next = newNode;
		ptail = newNode;
	}
	return p1;
}
struct ListNode* creatList2() {
	struct ListNode *p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	p2->next = NULL;
	struct ListNode *ptail = p2;
	int A[] = { 5,6,4 };
	int i;
	for (i = 0; i < 3; i++) {
		struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		newNode->val = A[i];
		newNode->next = NULL;
		ptail->next = newNode;
		ptail = newNode;
	}
	return p2;
}

struct ListNode* addTwoNumbers() {
	struct ListNode *p1 = creatList1();
	struct ListNode *p2 = creatList2();
	struct ListNode *phead = (struct ListNode*)malloc(sizeof(struct ListNode));
	phead->next = NULL;
	phead->val = 0;
	//struct ListNode *ptail = phead;
	int x, y, sum,ans;
	int carry = 0;
	while (p1 || p2) {
		if (p1) {
			x = p1->val;
			p1 = p1->next;
		}
		else x = 0;
		if (p2) {
			y = p2->val;
			p2 = p2->next;
		}
		else y = 0;
		sum = carry + x + y;
		carry = sum / 10;
		ans = sum % 10;
		struct ListNode *NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		NewNode->val = ans;
		NewNode->next = NULL;
		NewNode->next = phead->next ;  //替换头结点 
		phead->next = NewNode;               
	}
	if (carry > 0) {
		struct ListNode *NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		NewNode->val = 1;
		NewNode->next = NULL;
		NewNode->next = phead->next;  //替换头结点 
		phead = NewNode;
	}
	return phead;
}

//打印整个链表
void traverse(PNode pHead) {
	PNode p = pHead->next;
	while (p != NULL) {
		printf("%d   ", p->val);
		p = p->next;
	}
	printf("\n");
}

int main() {
	PNode p = addTwoNumbers();
	traverse(p);
	return 0;
}