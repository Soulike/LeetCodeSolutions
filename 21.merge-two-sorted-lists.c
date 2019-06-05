/*
 * @lc app=leetcode id=21 lang=c
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (47.36%)
 * Likes:    2249
 * Dislikes: 317
 * Total Accepted:    588.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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

// struct ListNode
// {
//     int val;
//     struct ListNode *next;
// };

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    if (l1 == NULL && l2 == NULL) // 都是 NULL 就返回 NULL
    {
        return NULL;
    }

    typedef struct ListNode ListNode;

    // 初始化新链表的头，头不记录数据
    ListNode *preNode = (ListNode *)malloc(sizeof(ListNode));
    preNode->next = NULL;

    ListNode *head = preNode;   // 记录链表头用于返回

    ListNode *l1CurrentNode = l1;
    ListNode *l2CurrentNode = l2;

    ListNode *newNode = NULL;

    while (l1CurrentNode != NULL && l2CurrentNode != NULL)
    {
        // 创建新结点，并设置好与前一个结点的链接关系
        newNode = (ListNode *)malloc(sizeof(ListNode));
        preNode->next = newNode;
        newNode->next = NULL;

        if (l1CurrentNode->val < l2CurrentNode->val)
        {
            newNode->val = l1CurrentNode->val;
            l1CurrentNode = l1CurrentNode->next;
        }
        else if (l1CurrentNode->val >= l2CurrentNode->val)
        {
            newNode->val = l2CurrentNode->val;
            l2CurrentNode = l2CurrentNode->next;
        }
        preNode = newNode;
    }

    // 有一条是 NULL 的话，处理另外一条
    ListNode *notNullChainNode = l1CurrentNode == NULL ? l2CurrentNode : l1CurrentNode;

    while (notNullChainNode != NULL)
    {
        newNode = (ListNode *)malloc(sizeof(ListNode));
        preNode->next = newNode;
        newNode->next = NULL;

        newNode->val = notNullChainNode->val;
        notNullChainNode = notNullChainNode->next;
        preNode = newNode;
    }

    ListNode *trueHead = head->next;
    free(head);
    return trueHead; // 头不纪录数据，因此返回下一个结点
}
