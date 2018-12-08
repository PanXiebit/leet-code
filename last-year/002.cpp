/*You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their 
nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/

/*
Example
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>


/*Definition for singly-linked list.*/
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *p1 = l1;
	struct ListNode *p2 = l2;
	struct ListNode *phead = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *ptail = phead;
	int x, y, sum, ans;
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
		ptail->next = NewNode;
		ptail = NewNode;
	}
	if (carry > 0) {
		struct ListNode *NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		NewNode->val = carry;
		NewNode->next = NULL;
		ptail->next = NewNode;
		ptail = NewNode;
	}
	return phead->next;
}