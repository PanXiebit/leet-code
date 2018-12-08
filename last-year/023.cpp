/*Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity*/
/*
����˼·�����κϲ������Ӵ�
ע���������飬vector�����Ԫ����ÿ�������ͷ��㡣
*/
#include<vector>
#include<iostream>
using namespace std;
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
extern ListNode * mergeTwoLists(ListNode* l1, ListNode* l2);
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * mergeKLists(vector<ListNode*>&lists) {   //ָ�����飬����Ԫ����ÿ�������ͷָ�룬lists[i]��ʾ��ַ��
		if (lists.empty()) return 0;
		ListNode* ppp = lists[0];
		for (int i = 1; i < lists.size(); i++)
			ppp = mergeTwoLists(ppp, lists[i]);
		return ppp;
	}
};

ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode dummy(-1);
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