/*
 * @lc app=leetcode id=33 lang=c
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (32.90%)
 * Likes:    2533
 * Dislikes: 319
 * Total Accepted:    431.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */

// https://www.cnblogs.com/grandyang/p/4325648.html
int search(int *nums, int numsSize, int target)
{
    if (numsSize == 0)
    {
        return -1;
    }

    if (numsSize == 1)
    {
        return nums[0] == target ? 0 : -1;
    }

    int midIndex = 0;

    int leftIndex = 0;
    int rightIndex = numsSize - 1;

    while (leftIndex <= rightIndex)
    {
        midIndex = leftIndex + (rightIndex - leftIndex) / 2;
        if (nums[midIndex] == target)
        {
            return midIndex;
        }

        if (nums[midIndex] > nums[rightIndex]) // 左半边是有序的
        {
            if (target <= nums[midIndex] && target >= nums[leftIndex]) // 在左半边
            {
                rightIndex = midIndex - 1;
            }
            else // 在右半边
            {
                leftIndex = midIndex + 1;
            }
        }
        else // nums[midIndex] < nums[rightIndex]  右半边是有序的
        {
            if (target <= nums[rightIndex] && target >= nums[midIndex]) // 在右半边
            {
                leftIndex = midIndex + 1;
            }
            else // 在左半边
            {
                rightIndex = midIndex - 1;
            }
        }
    }

    return -1;
}
