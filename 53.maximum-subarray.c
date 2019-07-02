/*
 * @lc app=leetcode id=53 lang=c
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (43.63%)
 * Likes:    4391
 * Dislikes: 152
 * Total Accepted:    544.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */

/*
动态规划
f(x) 表示从 x 位置（包括 x）向前看最大子数组和

f(0) = nums[0]
f(n) = f(n-1) > 0 ? f(n-1) + nums[n] : nums[n]
 */
int maxSubArray(int *nums, int numsSize)
{
    if (numsSize == 1)
    {
        return nums[0];
    }

    int max = nums[0];
    int last = nums[0];

    for (int i = 1; i < numsSize; i++)
    {
        if(last > 0)
        {
            last = last + nums[i];
        }
        else
        {
            last = nums[i];
        }

        if(max < last)
        {
            max = last;
        }
    }

    return max;
}
