/*
 * @lc app=leetcode id=35 lang=c
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (40.86%)
 * Likes:    1331
 * Dislikes: 179
 * Total Accepted:    407.6K
 * Total Submissions: 996.7K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */


int searchInsert(int* nums, int numsSize, int target)
{
    if(numsSize == 0)
    {
        return 0;
    }

    for (int i = 0; i < numsSize;i++)
    {
        if(nums[i] >= target)
        {
            return i;
        }
    }

    return numsSize;
}

