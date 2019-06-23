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
    int longestLen = 0;
    char *ret = (char *)malloc(sizeof(char));
    ret[0] = '\0';
    for (int i = 0; i < len; i++)
    {
        for (int j = len; j > 0; j--)
        {
            if (isPalindrome(s, i, j))
            {
                if (j - i > longestLen)
                {
                    longestLen = j - i;
                    free(ret);
                    ret = (char *)malloc((j - i + 1) * sizeof(char));
                    memcpy(ret, s + i, (j - i) * sizeof(char));
                    ret[j - i] = '\0';
                }
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