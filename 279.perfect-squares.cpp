/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (41.97%)
 * Likes:    1510
 * Dislikes: 119
 * Total Accepted:    190.7K
 * Total Submissions: 450.4K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3 
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */
#include <cmath>

// https://www.cnblogs.com/grandyang/p/4669134.html
class Solution
{
public:
    int numSquares(int n)
    {
        while (n % 4 == 0)
        {
            n /= 4;
        }
        if (n % 8 == 7)
        {
            return 4;
        }
        for (int a = 0; a * a <= n; ++a)
        {
            int b = sqrt(n - a * a);
            if (a * a + b * b == n)
            {
                return !!a + !!b;
            }
        }
        return 3;
    }
};
