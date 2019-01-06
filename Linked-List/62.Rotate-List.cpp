/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
*/


/*
解题思路：
将链接连接起来成为循环链表。如果 k 是链表长度的整数倍，那么链表不变，这样只需要考虑 k % length 次旋转之后的结果。 

新的尾节点是第 len-(k%len) 个节点，新的头节点是尾节点的下一个节点。
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;

        ListNode *newH = head;
        ListNode *tail = head;


        // computer teh length
        int length = 1;
        while(tail->next)
        {
            tail = tail->next;
            length ++;
        }

        tail->next = head;  // cycle the list

        if (k %= length)
        {
            for(int i=0; i<(length-k); i++)
            {
                tail = tail->next;
            }
        }
        newH = tail->next;
        tail->next = NULL;
        return newH;


    }
};
