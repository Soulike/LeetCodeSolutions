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

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool isPalindrome(char *s, int left, int right)
{
    right--;
    while (right > left)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

char *longestPalindrome(char *s)
{
    int len = strlen(s);
    char *ret = (char *)malloc(sizeof(char));
    ret[0] = '\0';
    for (int i = len; i > 0; i--)
    {
        for (int j = 0; j + i <= len; j++)
        {
            if (isPalindrome(s, j, j + i))
            {
                free(ret);
                ret = (char *)malloc((i + 1) * sizeof(char));
                memcpy(ret, s + j, i * sizeof(char));
                ret[i] = '\0';
                return ret;
            }
        }
    }
    return ret;
}

// int main()
// {
//     char *s = "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
//     char *t = longestPalindrome(s);
//     printf("%s", t);
// }