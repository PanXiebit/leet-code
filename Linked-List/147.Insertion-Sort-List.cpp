/*
Sort a linked list using insertion sort.

Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/

/*
 * my solution
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (prev->next || curr)
        {
            ListNode* p = &dummy;
            while(p->next->val <= curr->val && p->next!= curr)
            {
                p = p->next;
            }
            if (p->next == curr){
                curr = curr->next;
                prev = prev->next;
            }
            else
            {
                ListNode* tmp = curr;
                curr = curr->next;
                prev->next = curr;
                tmp->next = p->next;
                p->next = tmp;
            }
        }
        return dummy.next;
    }
};

// faster solution


