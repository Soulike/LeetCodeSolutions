/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (46.93%)
 * Likes:    1434
 * Dislikes: 41
 * Total Accepted:    239.2K
 * Total Submissions: 504.5K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */
#include <vector>

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int rowNum = grid.size();
        int colNum = grid.front().size();

        for (int i = 1; i < colNum; i++)
        {
            grid[0][i] += grid[0][i - 1];
        }

        for (int i = 1; i < rowNum; i++)
        {
            grid[i][0] += grid[i - 1][0];
        }

        for (int i = 1; i < rowNum;i++)
        {
            for (int j = 1; j < colNum;j++)
            {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid.back().back();
    }

    int min(int a, int b)
    {
        return a > b ? b : a;
    }
};
