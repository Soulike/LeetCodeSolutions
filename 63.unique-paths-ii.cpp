/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (33.47%)
 * Likes:    897
 * Dislikes: 130
 * Total Accepted:    207.6K
 * Total Submissions: 618.7K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 * 
 * 
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 * 
 * 
 */
#include <vector>
#include <utility>

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        const int rowNum = obstacleGrid.size();
        const int colNum = obstacleGrid.front().size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid.back().back() == 1)
        {
            return 0;
        }

        unsigned long long **pathNum = new unsigned long long *[rowNum];
        for (int i = 0; i < rowNum; i++)
        {
            pathNum[i] = new unsigned long long[colNum];
            fill(pathNum[i], pathNum[i] + colNum, 0);
        }

        pathNum[0][0] = 1;

        for (int i = 1; i < colNum; i++)
        {
            if (obstacleGrid[0][i] != 1)
            {
                pathNum[0][i] = pathNum[0][i - 1];
            }
            else
            {
                pathNum[0][i] = 0;
            }
        }

        for (int i = 1; i < rowNum; i++)
        {
            if (obstacleGrid[i][0] != 1)
            {
                pathNum[i][0] = pathNum[i - 1][0];
            }
            else
            {
                pathNum[i][0] = 0;
            }
        }

        for (int i = 1; i < rowNum; i++)
        {
            for (int j = 1; j < colNum; j++)
            {
                if (obstacleGrid[i][j] != 1)
                {
                    pathNum[i][j] = pathNum[i - 1][j] + pathNum[i][j - 1];
                }
            }
        }
        return pathNum[rowNum - 1][colNum - 1];
    }
};