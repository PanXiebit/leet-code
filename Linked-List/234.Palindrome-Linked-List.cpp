/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        if (!head->next) return true;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* low = &dummy;

        while(fast && fast->next)
        {
            fast = fast->next->next;
            low = low->next;
        }

        ListNode* second = low->next;

        ListNode dummy2(0);
        dummy2.next = second;

        ListNode* p = &dummy2;
        ListNode* q = p->next->next;
        p->next->next = NULL;
        while (q)
        {
            ListNode* temp = q->next;
            q->next = p->next;
            p->next = q;
            q = temp;
        }

        ListNode* m = dummy.next;
        ListNode* n = p->next;

        while(n)
        {
            if (m->val != n->val)
            {
                // cout << m->val << n->val << endl;
                break;
            }

            else
            {
                m = m->next;
                n = n->next;
            }
        }
        if (n == NULL) return true;
        else return false;
    }
};
