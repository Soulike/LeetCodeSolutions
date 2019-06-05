/*
 * @lc app=leetcode id=3 lang=c
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.40%)
 * Likes:    5583
 * Dislikes: 311
 * Total Accepted:    939.8K
 * Total Submissions: 3.3M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */

#include <string.h>

// [left, right)
char *findInString(char *left, char *right, char c)
{
    for (char *p = left; p < right; p++)
    {
        if (*p == c)
        {
            return p;
        }
    }
    return NULL;
}

int lengthOfLongestSubstring(char *s)
{
    if (s == NULL || *s == '\0')
    {
        return 0;
    }

    char *left = s;
    char *right = s + 1;
    char *pos = NULL;
    int longest = 1;
    while (*right != '\0')
    {
        longest = longest > right - left ? longest : right - left;
        pos = findInString(left, right, *right);
        if (pos == NULL)
        {
            right++;
        }
        else
        {
            left = pos + 1;
            right = left + 1;
        }
    }
    if (*right == '\0')
    {
        longest = longest > right - left ? longest : right - left;
    }
    return longest;
}
