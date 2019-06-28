/*
 * @lc app=leetcode id=17 lang=c
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (41.62%)
 * Likes:    2269
 * Dislikes: 306
 * Total Accepted:    403.3K
 * Total Submissions: 961.9K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <string.h>
#include <stdlib.h>

char *digitToLetters[] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz",
};

int charToIndex(char c)
{
    return c - '0';
}

char **letterCombinationsRecursive(char *digits, int left, int right, int *returnSize)
{
    int len = right - left;
    if (len > 1) // 如果数字字符串长度大于 1，就对半分，然后对左右两部分做排列组合
    {
        // 获得左半部分的排列组合
        int sizeLeft = 0;
        char **combinationsLeft = letterCombinationsRecursive(digits, left, left + len / 2, &sizeLeft);

        // 获得右半部分的排列组合
        int sizeRight = 0;
        char **combinationsRight = letterCombinationsRecursive(digits, left + len / 2, right, &sizeRight);

        *returnSize = sizeLeft * sizeRight;
        char **combinations = (char **)malloc(*returnSize * sizeof(char *));
        int currentIndex = 0;

        // 排列组合结果等长，因此取 0 的长度就可以
        int sizeLeftStr = strlen(combinationsLeft[0]);
        int sizeRightStr = strlen(combinationsRight[0]);
        char *combination = NULL;

        for (int i = 0; i < sizeLeft; i++)
        {
            for (int j = 0; j < sizeRight; j++)
            {
                combination = (char *)malloc((sizeLeftStr + sizeRightStr + 1) * sizeof(char));
                memcpy(combination, combinationsLeft[i], sizeLeftStr * sizeof(char));
                memcpy(combination + sizeLeftStr, combinationsRight[j], sizeRightStr * sizeof(char));
                combination[sizeLeftStr + sizeRightStr] = '\0';
                combinations[currentIndex++] = combination;
            }
            free(combinationsLeft[i]);
        }

        for (int i = 0; i < sizeRight; i++)
        {
            free(combinationsRight[i]);
        }

        return combinations;
    }
    else if (len > 0) // len <= 1 数字字符串长度是 1，就直接切割对应串返回
    {
        char *letters = digitToLetters[charToIndex(digits[left])];
        *returnSize = strlen(letters);
        char **combinations = (char **)malloc(*returnSize * sizeof(char *));

        char *str = NULL;
        for (int i = 0; i < *returnSize; i++)
        {
            str = (char *)malloc(2 * sizeof(char));
            str[0] = letters[i];
            str[1] = '\0';
            combinations[i] = str;
        }
        return combinations;
    }
    else // len <= 0 数字字符串长度是 0，直接返回空数组
    {
        *returnSize = 0;
        return (char **)malloc(0);
    }
}

char **letterCombinations(char *digits, int *returnSize)
{
    return letterCombinationsRecursive(digits, 0, strlen(digits), returnSize);
}
