/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/


// solution1: two pass solution
// 需要删除的节点是第  L-n+1 个节点。 L 为链表长度。所以遍历一次知道长度 L，在遍历一次到 L-n 个节点，删除下一个节点即可。
// 注意头节点的使用， dummy 是结构体对象，不是指针。

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;  // dummy 是结构体对象，不是指针，不能用 dummy->next.
        ListNode *tmp = head;
        int length = 0;
        while(tmp)
        {
            length ++;
            tmp = tmp->next;
        }
        length -= n;  // 第 len-n+1 个节点是需要删除的
        tmp = &dummy;
        while(length > 0)
        {
            length --;
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        return dummy.next;
    }
};

// solution2
// 用两个指针，相距 N 个节点，第一个指针指向第 N 个节点，第二个指针指向开始节点。同时移动，当前一个指针指向空时，后一个指针所在位置是需要删除的节点。

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* first = &dummy;
        ListNode* second = &dummy;
        
        for (int i=0; i<n; i++)
        {
            first = first->next;
        }
        
        while(first->next)
        {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
    return dummy.next;
    }    
};

// 需要注意的是必须要使用一个头节点，以为 head 节点可能会被删除掉。
