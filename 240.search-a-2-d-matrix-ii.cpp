/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (40.87%)
 * Likes:    1569
 * Dislikes: 45
 * Total Accepted:    187.4K
 * Total Submissions: 457K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * 
 * Example:
 * 
 * Consider the following matrix:
 * 
 * 
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 * 
 * 
 * Given target = 5, return true.
 * 
 * Given target = 20, return false.
 * 
 */
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rowNum = matrix.size();
        if (rowNum == 0)
        {
            return false;
        }
        int colNum = matrix.front().size();
        if (colNum == 0)
        {
            return false;
        }

        if (rowNum == 1 && colNum == 1)
        {
            return target == matrix[0][0];
        }

        int min = matrix.front().front();
        int max = matrix.back().back();
        if (target < min || target > max)
        {
            return false;
        }
        else if (target == min || target == max)
        {
            return true;
        }
        else // target > min || target < max
        {
            int currentX = rowNum - 1;
            int currentY = 0;
            while (currentX >= 0 && currentY < colNum)
            {
                if (target == matrix[currentX][currentY])
                {
                    return true;
                }
                else if (target > matrix[currentX][currentY])
                {
                    currentY++;
                }
                else // target < matrix[currentX][currentY]
                {
                    currentX--;
                }
            }
            return false;
        }
    }
};