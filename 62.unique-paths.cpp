/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (47.65%)
 * Likes:    1665
 * Dislikes: 116
 * Total Accepted:    300.4K
 * Total Submissions: 625.2K
 * Testcase Example:  '3\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * How many possible unique paths are there?
 * 
 * 
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the
 * bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 7, n = 3
 * Output: 28
 * 
 */
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m == 1 || n == 1)
        {
            return 1;
        }
        m--;
        n--;
        if (m < n)
        {
            swap(m, n);
        }
        int sum = 0;

        for (int i = 0; i <= n - 1; i++)
        {
            sum += comb(m + 1, i + 1) * comb(n - 1, i);
        }
        return sum;
    }

    inline void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    // 计算组合数C(m,n)
    int comb(int m, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return m;
        }
        n = max(n, m - n);
        if (n == m)
        {
            return 1;
        }
        if (n == m - 1)
        {
            return m;
        }

        int prev = comb(m - 1, n - 1);
        int rest = prev % n;
        return prev / n * m + rest * m / n;
    }

    int max(int a, int b)
    {
        return a > b ? a : b;
    }
};