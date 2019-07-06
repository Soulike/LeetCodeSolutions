/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (35.43%)
 * Likes:    1497
 * Dislikes: 78
 * Total Accepted:    191.1K
 * Total Submissions: 531.7K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cstdlib>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if(head == NULL)
        {
            return NULL;
        }
        return listMergeSort(head);
    }

    ListNode *listMergeSort(ListNode *head)
    {
        if (head->next == NULL)
        {
            return head;
        }

        ListNode *fast = head;
        ListNode *slow = head;

        // 利用快慢指针找到中间点
        while (true)
        {

            fast = fast->next;
            if (fast == NULL)
            {
                break;
            }
            fast = fast->next;
            if (fast == NULL)
            {
                break;
            }
            slow = slow->next;
        }

        // 拆分两个链表
        ListNode *leftHead = head;
        ListNode *rightHead = slow->next;
        slow->next = NULL;

        leftHead = listMergeSort(leftHead);
        rightHead = listMergeSort(rightHead);

        return merge(leftHead, rightHead);
    }

    ListNode *merge(ListNode *leftHead, ListNode *rightHead)
    {
        if (leftHead == NULL)
        {
            return rightHead;
        }
        if (rightHead == NULL)
        {
            return leftHead;
        }

        ListNode *head = NULL;
        ListNode *currentNode = NULL;
        ListNode *currentLeftNode = leftHead;
        ListNode *currentRightNode = rightHead;

        if (currentLeftNode->val < currentRightNode->val)
        {
            head = currentNode = currentLeftNode;
            currentLeftNode = currentLeftNode->next;
        }
        else // currentLeftNode->val >= currentRightNode->val
        {
            head = currentNode = currentRightNode;
            currentRightNode = currentRightNode->next;
        }

        while (currentLeftNode != NULL && currentRightNode != NULL)
        {
            if (currentLeftNode->val < currentRightNode->val)
            {
                currentNode->next = currentLeftNode;
                currentLeftNode = currentLeftNode->next;
            }
            else // currentLeftNode->val >= currentRightNode->val
            {
                currentNode->next = currentRightNode;
                currentRightNode = currentRightNode->next;
            }
            currentNode = currentNode->next;
        }

        if (currentLeftNode != NULL && currentRightNode == NULL)
        {
            currentNode->next = currentLeftNode;
        }
        else if (currentLeftNode == NULL && currentRightNode != NULL)
        {
            currentNode->next = currentRightNode;
        }
        else // currentLeftNode == NULL && currentRightNode == NULL
        {
            currentNode->next = NULL;
        }

        return head;
    }
};
