/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (41.57%)
 * Likes:    2722
 * Dislikes: 99
 * Total Accepted:    374.2K
 * Total Submissions: 892.1K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */
#include <vector>

using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int num = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    num++;
                    dfsAndRemove1s(grid, i, j);
                }
            }
        }
        return num;
    }

    void dfsAndRemove1s(vector<vector<char>> &grid, int x, int y)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size())
        {
            return;
        }

        if (grid[x][y] == '0')
        {
            return;
        }

        grid[x][y] = '0';
        dfsAndRemove1s(grid, x - 1, y);
        dfsAndRemove1s(grid, x + 1, y);
        dfsAndRemove1s(grid, x, y - 1);
        dfsAndRemove1s(grid, x, y + 1);
    }
};