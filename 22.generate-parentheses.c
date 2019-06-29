/*
 * @lc app=leetcode id=22 lang=c
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (54.99%)
 * Likes:    2870
 * Dislikes: 180
 * Total Accepted:    352.3K
 * Total Submissions: 635.1K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * [
 * ⁠ "(())",
 * ⁠ "()()",
 * ⁠ "())(",
 * ⁠ ")(()",
 * ⁠ ")()("
 * ]
 * 
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <string.h>
#include <stdlib.h>

struct CharArray
{
    char *str;
    int length;
    int capacity;
};

typedef struct CharArray CharArray;

CharArray *createCharArray()
{
    CharArray *arr = (CharArray *)malloc(sizeof(CharArray));
    arr->str = (char *)malloc(10 * sizeof(char));
    arr->length = 0;
    arr->capacity = 10;
    return arr;
}

void destroyCharArray(CharArray *array)
{
    free(array->str);
    free(array);
}

void expandCharArray(CharArray *array)
{
    char *newStr = (char *)malloc(2 * array->capacity * sizeof(char));
    memcpy(newStr, array->str, array->length * sizeof(char));
    free(array->str);
    array->str = newStr;
    array->capacity *= 2;
}

void pushCharArray(CharArray *array, char c)
{
    if (array->length == array->capacity)
    {
        expandCharArray(array);
    }

    array->str[array->length++] = c;
}

void popCharArray(CharArray *array)
{
    array->length--;
}

char *toString(CharArray *array)
{
    char *ret = (char *)malloc((array->length + 1) * sizeof(char));
    memcpy(ret, array->str, array->length * sizeof(char));
    ret[array->length] = '\0';
    return ret;
}

CharArray *cloneCharArray(CharArray *array)
{
    CharArray *newArray = malloc(sizeof(CharArray));
    newArray->length = array->length;
    newArray->capacity = array->capacity;
    newArray->str = (char *)malloc(array->capacity * sizeof(char));
    memcpy(newArray->str, array->str, array->length * sizeof(char));
    return newArray;
}

struct StringArray
{
    char **strArray;
    int length;
    int capacity;
};

typedef struct StringArray StringArray;

StringArray *createStringArray()
{
    StringArray *arr = (StringArray *)malloc(sizeof(StringArray));
    arr->strArray = (char **)malloc(10 * sizeof(char *));
    arr->length = 0;
    arr->capacity = 10;
    return arr;
}

void destroyStringArray(StringArray *array)
{
    free(array->strArray);
    free(array);
}

void expandStringArray(StringArray *array)
{
    char **newStrArray = (char **)malloc(2 * array->capacity * sizeof(char *));
    memcpy(newStrArray, array->strArray, array->length * sizeof(char));
    free(array->strArray);
    array->strArray = newStrArray;
    array->capacity *= 2;
}

void pushStringArray(StringArray *array, char *str)
{
    if (array->length == array->capacity)
    {
        expandStringArray(array);
    }

    array->strArray[array->length++] = str;
}

void generateRecursive(int n, CharArray *cArray, StringArray *sArray)
{

    // 第一个一定是左括号
    if (cArray->length == 0)
    {
        pushCharArray(cArray, '(');
        generateRecursive(n, cArray, sArray);
        popCharArray(cArray);
        return;
    }

    // 最后一个一定是右括号
    if (cArray->length == 2 * n - 1)
    {
        pushCharArray(cArray, ')');
        generateRecursive(n, cArray, sArray);
        popCharArray(cArray);
        return;
    }

    // ( 为 -1 ) 为 1，计算累加和
    int sum = 0;
    int leftNum = 0;
    for (int i = 0; i < cArray->length; i++)
    {
        sum += cArray->str[i] == '(' ? -1 : 1;
        if(cArray->str[i] == '(')
        {
            leftNum++;
        }
    }

    // 长度已经满足，返回
    if (cArray->length == 2 * n)
    {
        // 只有完全配对的返回
        if (sum == 0)
        {
            pushStringArray(sArray, toString(cArray));
        }
        return;
    }

    if (sum < 0) // 有多余的左括号
    {
        if (leftNum < n)
        {
            pushCharArray(cArray, '(');
            generateRecursive(n, cArray, sArray);
            popCharArray(cArray);
        }

        pushCharArray(cArray, ')');
        generateRecursive(n, cArray, sArray);
        popCharArray(cArray);
    }
    else if (sum == 0 && leftNum < n) // 没有多余的左括号
    {
        pushCharArray(cArray, '(');
        generateRecursive(n, cArray, sArray);
        popCharArray(cArray);
    }
}

char **generateParenthesis(int n, int *returnSize)
{
    StringArray *sArray = createStringArray();
    CharArray *cArray = createCharArray();
    generateRecursive(n, cArray, sArray);

    *returnSize = sArray->length;
    return sArray->strArray;
}

// int main()
// {
//     int retSize = -1;
//     generateParenthesis(10, &retSize);
// }