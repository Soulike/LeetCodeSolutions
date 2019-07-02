/*
 * @lc app=leetcode id=32 lang=c
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (25.52%)
 * Likes:    1938
 * Dislikes: 92
 * Total Accepted:    196.6K
 * Total Submissions: 764.4K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct Stack
{
    int *container;
    int length;
    int capacity;
};

typedef struct Stack Stack;

Stack *createStack()
{
    Stack *s = malloc(sizeof(Stack));
    s->container = malloc(10 * sizeof(int));
    s->length = 0;
    s->capacity = 10;
    return s;
}

void destoryStack(Stack *s)
{
    free(s->container);
    free(s);
}

void expand(Stack *s)
{
    int *newContainer = malloc(2 * s->capacity * sizeof(int));
    memcpy(newContainer, s->container, s->length * sizeof(int));
    free(s->container);
    s->container = newContainer;
    s->capacity *= 2;
}

void push(Stack *s, int e)
{
    if (s->length == s->capacity)
    {
        expand(s);
    }
    s->container[s->length++] = e;
}

void pop(Stack *s)
{
    s->length--;
}

int top(Stack *s)
{
    return s->container[s->length - 1];
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int longestValidParentheses(char *s)
{
    int len = strlen(s);
    if (len == 0 || len == 1)
    {
        return 0;
    }

    int maxLen = 0;

    Stack *stack = createStack();
    Stack *indexStack = createStack();

    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(')
        {
            push(stack, '(');
            push(indexStack, i);
        }
        else // s[i] == ')'
        {
            // 正确配对弹出
            if (stack->length != 0 && top(stack) == '(')
            {
                pop(stack);
                pop(indexStack);
            }
            // 不配对，放进栈中做分界符
            else
            {
                push(stack, ')');
                push(indexStack, i);
            }
        }
    }

    if (stack->length == 0)
    {
        return len;
    }

    // 寻找分界符之间的最大间隔，-1 与 len 也是分界符
    int lastIndex = len;
    while (stack->length != 0)
    {
        maxLen = max(maxLen, lastIndex - top(indexStack) - 1);
        lastIndex = top(indexStack);
        pop(stack);
        pop(indexStack);
    }
    maxLen = max(maxLen, lastIndex);
    //即为 maxLen = max(maxLen, lastIndex - (-1) - 1);

    destoryStack(stack);
    destoryStack(indexStack);

    return maxLen;
}