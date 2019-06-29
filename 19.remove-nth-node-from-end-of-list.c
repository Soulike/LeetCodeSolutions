/*
 * @lc app=leetcode id=19 lang=c
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.26%)
 * Likes:    1896
 * Dislikes: 137
 * Total Accepted:    407.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdbool.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // before 和 after 之间始终差 n 个节点
    ListNode *prevBefore = NULL;
    ListNode *before = head;
    ListNode *after = head;

    for (int i = 0; i < n; i++)
    {
        after = after->next;
    }

    while (after != NULL)
    {
        prevBefore = before;
        before = before->next;
        after = after->next;
    }

    if (before != head)
    {
        prevBefore->next = before->next;
    }
    else // before == head
    {
        head = head->next;
    }

    free(before);

    return head;
}
