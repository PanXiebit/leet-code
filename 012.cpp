#include<malloc.h>
#include<stdio.h>


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* phead = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* ptail = phead;
	struct ListNode *p1 = l1;
	struct ListNode *p2 = l2;
	while (p1 && p2) {
		struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		if (p1->val >= p2->val) {
			newNode->val = p1->val;
			p1 = p1->next;			
		}
		else {
			newNode->val = p2->val;
			p2 = p2->next;
		}
		newNode->next = NULL;
		ptail->next = newNode;
		ptail = newNode;
	}
	if (p1->next != NULL) { ptail->next = p1;}
	if (p2->next != NULL) { ptail->next = p2; }
	return phead->next;
}
int main() {
	struct ListNode *l1;
	struct ListNode *l2;
	mergeTwoLists(l1, l2);
	return 0;
}