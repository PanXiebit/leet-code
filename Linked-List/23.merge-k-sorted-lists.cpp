/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/


/*
解题思路： 
这道题主要可以用来熟悉链表的操作，注意头节点的使用
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// solution1
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        ListNode* resHead = lists[0];
        for (int i=1; i < lists.size(); i++)
            resHead = mergeTwoList(resHead, lists[i]);
        return resHead;
    }

    ListNode* mergeTwoList(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(-1);
        ListNode* trail = &dummy;
        while(l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                trail->next = l1;
                l1 = l1->next;
            }
            else
            {
                trail->next = l2;
                l2 = l2->next;
            }
            trail = trail->next;
        }
        trail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

//solution2

