/*
 * @lc app=leetcode id=14 lang=c
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.54%)
 * Likes:    1368
 * Dislikes: 1313
 * Total Accepted:    469K
 * Total Submissions: 1.4M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize)
{
    if(strsSize == 0)
    {
        return "";
    }

    if(strsSize == 1)
    {
        return strs[0];
    }

    if(strlen(strs[0]) == 0)
    {
        return "";
    }

    int commonPrefixLength = 0; // 最大前缀长度
    char c = '\0';              // 当前比对字符
    bool hasGotLongest = false;
    while (!hasGotLongest)
    {
        c = strs[0][commonPrefixLength];
        for (int i = 1; i < strsSize; i++)
        {
            if (strlen(strs[i]) <= commonPrefixLength || strs[i][commonPrefixLength] != c)
            {
                hasGotLongest = true;
                break;
            }
        }

        if (!hasGotLongest)
        {
            commonPrefixLength++;
        }
    }

    char *prefix = (char *)malloc((commonPrefixLength + 1) * sizeof(char));
    memcpy(prefix, strs[0], commonPrefixLength * sizeof(char));
    prefix[commonPrefixLength] = '\0';

    return prefix;
}
