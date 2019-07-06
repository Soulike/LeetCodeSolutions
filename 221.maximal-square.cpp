/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (33.05%)
 * Likes:    1357
 * Dislikes: 34
 * Total Accepted:    135.4K
 * Total Submissions: 405.9K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 * 
 */
#include <vector>

using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int rowSize = matrix.size();

        if (rowSize == 0)
        {
            return 0;
        }

        int colSize = matrix.front().size();
        int max = 0;

        if (rowSize == 1)
        {
            for (int i = 0; i < colSize; i++)
            {
                if (matrix[0][i] == '1')
                {
                    return 1;
                }
            }
            return 0;
        }
        else if (colSize == 1)
        {
            for (int i = 0; i < rowSize; i++)
            {
                if (matrix[i][0] == '1')
                {
                    return 1;
                }
            }
            return 0;
        }
        else
        {
            vector<vector<int>> length(rowSize, vector<int>(colSize, 0));

            for (int i = 0; i < rowSize; i++)
            {
                length[i][0] = matrix[i][0] - '0';
                if (matrix[i][0] == '1')
                {
                    max = 1;
                }
            }

            for (int i = 0; i < colSize; i++)
            {
                length[0][i] = matrix[0][i] - '0';
                if (matrix[0][i] == '1')
                {
                    max = 1;
                }
            }

            for (int i = 1; i < rowSize; i++)
            {
                for (int j = 1; j < colSize; j++)
                {
                    if (matrix[i][j] == '1')
                    {
                        length[i][j] = min(length[i - 1][j], length[i][j - 1], length[i - 1][j - 1]) + 1;
                        if (length[i][j] > max)
                        {
                            max = length[i][j];
                        }
                    }
                }
            }
        }
        return max * max;
    }

    int min(int a, int b, int c)
    {
        return a < b ? (a < c ? a : c) : (b < c ? b : c);
    }
};
