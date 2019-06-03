/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.15%)
 * Likes:    5220
 * Dislikes: 1344
 * Total Accepted:    882.2K
 * Total Submissions: 2.8M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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

// 在提交时需要注释这个结构体
// struct ListNode
// {
//     int val;
//     struct ListNode *next;
// };

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *newNode = NULL;
    struct ListNode *head = NULL;
    struct ListNode *lastNode = NULL;
    struct ListNode *l1Node = l1;
    struct ListNode *l2Node = l2;
    int needPlusOne = 0; // 是否要在下一次计算时加上进位
    int currentCalResult = 0;

    while (l1Node != NULL || l2Node != NULL)
    {
        // 新节点处理
        newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            lastNode->next = newNode;
        }
        lastNode = newNode;

        currentCalResult = 0;
        // 值计算
        if (l1Node != NULL)
        {
            currentCalResult += l1Node->val;
            l1Node = l1Node->next;
        }

        if (l2Node != NULL)
        {
            currentCalResult += l2Node->val;
            l2Node = l2Node->next;
        }

        // 计算个位并加上进位
        newNode->val = (currentCalResult + needPlusOne) % 10;

        // 判断是否有进位
        if (currentCalResult + needPlusOne >= 10)
        {
            needPlusOne = 1;
        }
        else
        {
            needPlusOne = 0;
        }
    }

    // 运算结束了还存在进位，需要单独处理
    if (needPlusOne == 1)
    {
        newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        lastNode->next = newNode;
        lastNode = newNode;
        newNode->val = 1;
    }
    return head;
}
