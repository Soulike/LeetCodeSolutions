/*
 * @lc app=leetcode id=58 lang=c
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.27%)
 * Likes:    377
 * Dislikes: 1584
 * Total Accepted:    272.3K
 * Total Submissions: 844K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 * 
 * 
 */

#include <string.h>

int lastIndexOf(char *str, char c)
{
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == c)
        {
            return i;
        }
    }
    return -1;
}

void trimRight(char *str)
{
    int len = strlen(str);
    if (len != 0)
    {
        int index = -1;
        for (int i = len - 1; i >= 0; i--)
        {
            if (str[i] != ' ')
            {
                index = i;
                break;
            }
        }

        str[index + 1] = '\0';
    }
}

int lengthOfLastWord(char *s)
{
    trimRight(s);
    int index = lastIndexOf(s, ' ');
    int len = strlen(s);
    if(index == -1)
    {
        return len;
    }
    return len - index - 1;
}
