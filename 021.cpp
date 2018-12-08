/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

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
		if (p1->val <= p2->val) {
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
	if (p1 == NULL) { ptail->next = p2; }
	if (p2 == NULL) { ptail->next = p1; }
	return phead->next;
}
int main() {
	struct ListNode *l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l1->val = 5;
	l1->next = NULL;
	struct ListNode *l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l2->val = 4;
	l2->next = NULL;
	mergeTwoLists(l1, l2);
	return 0;
}

#include<iostream>
#include <stdlib.h>
using namespace std;
//C++
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode dummy(INT_MIN);
		ListNode *tail = &dummy;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				tail->next = l1;
				l1 = l1->next;
			}
			else {
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}
		tail->next = l1 ? l1 : l2;
		return dummy.next;
	}
};

//RECURSIVE SOLUTION
class Solution {
public:
	ListNode * mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;

		if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l2->next, l1);
			return l2;
		}
	}
};