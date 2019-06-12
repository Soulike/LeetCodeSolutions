/*
 * @lc app=leetcode id=28 lang=c
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (32.04%)
 * Likes:    890
 * Dislikes: 1312
 * Total Accepted:    434.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */

#include <string.h>
#include <stdbool.h>

int strStr(char *haystack, char *needle)
{
    int haystackSize = strlen(haystack);
    int needleSize = strlen(needle);
    if (needleSize == 0)
    {
        return 0;
    }

    int occurIndex = 0;
    bool got = false; // 是否已经找到匹配

    for (int i = 0; i < haystackSize; i++)
    {
        if (haystack[i] == needle[0])
        {
            got = true;
            occurIndex = i;
            for (int j = 1, k = i+1; j < needleSize; j++, k++)
            {
                if (k == haystackSize || haystack[k] != needle[j])
                {
                    got = false;
                    break;
                }
            }
        }

        if (got)
        {
            break;
        }
    }

    if (got)
    {
        return occurIndex;
    }
    else
    {
        return -1;
    }
}
