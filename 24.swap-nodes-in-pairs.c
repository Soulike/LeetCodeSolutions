/*
 * @lc app=leetcode id=24 lang=c
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (44.74%)
 * Likes:    1195
 * Dislikes: 105
 * Total Accepted:    325.6K
 * Total Submissions: 721.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given aÂ linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

/*
1. 记录下一个节点的 next 为 originalNextNext，如果下一个节点是 NULL 退出
2. 将下一个节点的 next 改成自己，如果自己是 head，把 head 改为下一个节点
3. 记录当前节点的 next 为 originalNext
3. 将当前节点的 next 改成 originalNextNext->next，如果originalNextNext是 NULL 改成 NULL，如果 originalNextNext->next 是 NULL 就改为 originalNextNext
5. 当前节点改为 originalNextNext，不是 NULL 时回到 1，否则退出
 */

ListNode *swapPairs(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *currentNode = head;
    ListNode *originalNextNext = NULL;
    ListNode *originalNext = NULL;

    while (true)
    {
        if (currentNode->next == NULL)
        {
            break;
        }
        originalNextNext = currentNode->next->next;

        currentNode->next->next = currentNode;
        if (head == currentNode)
        {
            head = currentNode->next;
        }
        originalNext = currentNode->next;
        currentNode->next = originalNextNext == NULL ? NULL : originalNextNext->next == NULL ? originalNextNext : originalNextNext->next;
        currentNode = originalNextNext;
        if (currentNode == NULL)
        {
            break;
        }
    }
    return head;
}
