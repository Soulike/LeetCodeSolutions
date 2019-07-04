/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (44.21%)
 * Likes:    2303
 * Dislikes: 84
 * Total Accepted:    422.7K
 * Total Submissions: 951.2K
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * Note: Given n will be a positive integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 * 
 * 
 */
class Solution
{
public:
    int climbStairs(int n)
    {
        int a = 1, b = 1, c = 2;
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return b;
        }
        if (n == 2)
        {
            return c;
        }
        for (int i = 3; i <= n; i++)
        {
            a = b;
            b = c;
            c = a + b;
        }
        return c;
    }
};
