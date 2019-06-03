/*
 * @lc app=leetcode id=20 lang=c
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.54%)
 * Likes:    2917
 * Dislikes: 144
 * Total Accepted:    595.9K
 * Total Submissions: 1.6M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Stack
{
    char *array;
    int length;
    int capacity;
};

typedef struct Stack Stack;

void expand(Stack *stack)
{
    char *newArray = (char *)malloc(stack->capacity * 2 * sizeof(char));
    memcpy(newArray, stack->array, stack->capacity * sizeof(char));
    free(stack->array);
    stack->array = newArray;
    stack->capacity *= 2;
}

Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->array = (char *)malloc(10 * sizeof(char));
    stack->length = 0;
    stack->capacity = 10;
    return stack;
}

void destroyStack(Stack *stack)
{
    free(stack->array);
    free(stack);
}

void push(Stack *stack, char element)
{
    if (stack->length == stack->capacity)
    {
        expand(stack);
    }
    stack->array[stack->length++] = element;
}

void pop(Stack *stack)
{
    stack->length--;
}

char top(Stack *stack)
{
    return stack->array[stack->length - 1];
}

bool isValid(char *s)
{
    int length = strlen(s);
    bool isValid = true;
    Stack *stack = createStack();
    for (int i = 0; i < length && isValid; i++)
    {
        switch (s[i])
        {
        case '(':
        case '[':
        case '{':
        {
            push(stack, s[i]);
            break;
        }
        case ')':
        {
            if (stack->length != 0 && top(stack) == '(')
            {
                pop(stack);
            }
            else
            {
                isValid = false;
            }
            break;
        }
        case ']':
        {
            if (stack->length != 0 && top(stack) == '[')
            {
                pop(stack);
            }
            else
            {
                isValid = false;
            }
            break;
        }
        case '}':
        {
            if (stack->length != 0 && top(stack) == '{')
            {
                pop(stack);
            }
            else
            {
                isValid = false;
            }
            break;
        }

        default:
            break;
        }
    }

    if(isValid && stack->length != 0)
    {
        isValid = false;
    }

    destroyStack(stack);
    return isValid;
}
