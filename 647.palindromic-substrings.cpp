/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (56.97%)
 * Likes:    1421
 * Dislikes: 74
 * Total Accepted:    103.9K
 * Total Submissions: 181.4K
 * Testcase Example:  '"abc"'
 *
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 * 
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters.
 * 
 * Example 1:
 * 
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The input string length won't exceed 1000.
 * 
 * 
 * 
 * 
 */
#include <string>

using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        if(s.size() == 0)
        {
            return 0;
        }

        if(s.size() == 1)
        {
            return 1;
        }

        bool **isPalindromic = new bool *[s.size()];
        int count = 0;

        for (int i = 0; i < s.size(); i++)
        {
            isPalindromic[i] = new bool[s.size()];
            fill(isPalindromic[i], isPalindromic[i] + s.size(), false);
        }

        for (int j = 0; j < s.size(); j++)
        {
            isPalindromic[j][j] = true;
            count++;
            for (int i = j - 1; i >= 0; i--)
            {
                if (j - i == 1 && s[i] == s[j])
                {
                    isPalindromic[i][j] = true;
                    count++;
                }
                else if (j - i > 1 && s[i] == s[j] && isPalindromic[i + 1][j - 1] == true)
                {
                    isPalindromic[i][j] = true;
                    count++;
                }
            }
        }
        return count;
    }
};
