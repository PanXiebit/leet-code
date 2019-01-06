/*

Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
 * 归并排序
 */

class Solution {
public:
    ListNode* getMid(ListNode* head)
    {
        if (!head) return NULL;
        if (!head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode dummy(-1);
		ListNode *tail = &dummy;

        while(l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                tail = tail->next;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                tail = tail->next;
                l2 = l2->next;
            }
        }
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;
        return dummy.next;
    }


    ListNode* sortList(ListNode* head)
    {
        if (!head) return NULL;
        if (head->next==NULL) return head;
        // 找到中间点
        ListNode *mid = getMid(head);
        // 将链表分成两个子链表
        ListNode *nextPart = NULL;
        if (mid)
        {
            nextPart = mid->next;
            mid->next = NULL;
        }
        return mergeLists(sortList(head), sortList(nextPart));
    }
};
