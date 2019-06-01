/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

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
    if(needPlusOne == 1)
    {
        newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        lastNode->next = newNode;
        lastNode = newNode;
        newNode->val = 1;
    }
    return head;
}

int main()
{
    struct ListNode *l1 = NULL;
    struct ListNode *l2 = NULL;
    l1 = malloc(sizeof(struct ListNode *));
    l1->next = NULL;
    l1->val = 1;

    l2 = malloc(sizeof(struct ListNode *));
    l2->next = NULL;
    l2->val = 9;

    struct ListNode *temp = malloc(sizeof(struct ListNode *));
    temp->next = NULL;
    temp->val = 9;
    l2->next = temp;

    struct ListNode *ret = addTwoNumbers(l1, l2);

}