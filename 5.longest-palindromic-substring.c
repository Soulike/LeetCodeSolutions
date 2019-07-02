/*
 * @lc app=leetcode id=5 lang=c
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.31%)
 * Likes:    3747
 * Dislikes: 356
 * Total Accepted:    577.7K
 * Total Submissions: 2.1M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *longestPalindrome(char *s)
{
    int len = strlen(s);
    if(len == 0)
    {
        return "";
    }

    if(len == 1)
    {
        return s;
    }

    bool(*isPalindrome)[len] = (bool(*)[len])malloc(len * len * sizeof(bool)); // 从 i 到 j 是回文
    memset(isPalindrome, false, len * len * sizeof(bool));

    int left = 0;
    int right = 0;
    int maxLen = 1;

    for (int j = 0; j < len; j++)
    {
        isPalindrome[j][j] = 1;
        for (int i = 0; i < j; i++)
        {
            if (j == i + 1 && s[i] == s[j])
            {
                isPalindrome[i][j] = true;
                if (j - i + 1 > maxLen)
                {
                    left = i;
                    right = j;
                    maxLen = j - i + 1;
                }
            }
            else if (j > i + 1 && s[i] == s[j] && isPalindrome[i + 1][j - 1])
            {
                isPalindrome[i][j] = true;
                if (j - i + 1 > maxLen)
                {
                    left = i;
                    right = j;
                    maxLen = j - i + 1;
                }
            }
        }
    }

    char *ret = malloc((maxLen + 1) * sizeof(char));
    memcpy(ret, s + left, maxLen * sizeof(char));
    ret[maxLen] = '\0';
    return ret;
}