/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (!head) return NULL;
        if (head->next == NULL) return head;

        ListNode *p = head;
        ListNode *q = head->next;

        while(p && p->next)
        {
            if (p->val == q->val)
            {
                q = q->next;
            }
            else
            {
                p->next = q;
                p = p->next;
                q = q->next;
            }
            if (q == NULL)         // 当最后一个数也是 duplicate 时，q=NULL，这时 q->val 就没有意义了。
                p->next = NULL;
        }
        return head;
    }
};
