/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/
#include <algorithm>
#include <iostream>
#include <list>


// Definition for singly-linked list.
struct ListNode {
    int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode temp(0);
		temp.next = head;
		ListNode *p = &temp, *q, *r;
		while (p->next&&p->next->next) {
			q = p->next;
			r = q->next;
			p->next = r;
			q->next = r->next;
			r->next = q;
			
			p = q;
			
		}
		return temp.next;
	}
};

int main() {
	ListNode *phead = (ListNode*)malloc(sizeof(ListNode));
	phead->next = NULL;
	ListNode *ptail = phead;
	for (int i = 0; i < 2; i++) {
		ListNode *pNode = (ListNode*)malloc(sizeof(ListNode));
		pNode->val = i+1;
		pNode->next = NULL;
		ptail->next = pNode;
		ptail = pNode;
	}
	Solution sss;
	sss.swapPairs(phead->next);
	return 0;
}