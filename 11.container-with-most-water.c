/*
 * @lc app=leetcode id=11 lang=c
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (44.64%)
 * Likes:    3394
 * Dislikes: 446
 * Total Accepted:    387.4K
 * Total Submissions: 860.2K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 * 
 * 
 * 
 * 
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49. 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * 
 */

#include <stdbool.h>

inline int min(int a, int b)
{
    return a < b ? a : b;
}

int maxArea(int *height, int heightSize)
{
    int *left = &height[0];
    int *right = &height[heightSize - 1];

    int prevLeftHeight = 0;
    int prevRightHeight = 0;

    int maxArea = 0;
    int currentArea = 0;

    while (right > left)
    {
        currentArea = min(*left, *right) * (right - left);
        if (currentArea > maxArea)
        {
            maxArea = currentArea;
        }

        if (*left > *right)
        {
            prevRightHeight = *right;
            right--;
            while (left < right && *right <= prevRightHeight)
            {
                prevRightHeight = *right;
                right--;
            }
        }
        else
        {
            prevLeftHeight = *left;
            left++;
            while (left < right && *left <= prevLeftHeight)
            {
                prevLeftHeight = *left;
                left++;
            }
        }
    }

    return maxArea;
}
