/*
 * @lc app=leetcode id=16 lang=c
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.78%)
 * Likes:    1152
 * Dislikes: 84
 * Total Accepted:    355.2K
 * Total Submissions: 776.1K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
#include<stdint.h>

int abs(int x)
{
    return x < 0 ? -x : x;
}

int threeSumClosest(int *nums, int numsSize, int target)
{
    int closestNum = 0;
    int closestDelta = INT32_MAX;
    int currentDelta = INT32_MAX;

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            for (int k = j + 1; k < numsSize; k++)
            {
                currentDelta =  abs(nums[i] + nums[j] + nums[k] - target);
                if (currentDelta < closestDelta)
                {
                    closestNum = nums[i] + nums[j] + nums[k];
                    closestDelta = currentDelta;
                }
            }
        }
    }

    return closestNum;
}
