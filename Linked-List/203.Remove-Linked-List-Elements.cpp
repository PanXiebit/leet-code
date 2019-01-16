/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return NULL;

        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = &dummy;

        while(p && p->next)
        {
            if (p->next->val == val)
                p->next = p->next->next; // 这里需要注意，删除节点之后 p 不能后移，而需要继续检验新来的节点
            else
                p = p->next;
        }
        return dummy.next;
    }
};
