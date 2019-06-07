/*
 * @lc app=leetcode id=26 lang=c
 *
 * [26] Remove Duplicates from Sorted Array
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 *
 * algorithms
 * Easy (40.76%)
 * Likes:    1517
 * Dislikes: 3264
 * Total Accepted:    598.1K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted array nums, remove the duplicates in-place such that each
 * element appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * Example 1:
 * 
 * 
 * Given nums = [1,1,2],
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively.
 * 
 * It doesn't matter what you leave beyond the returned length.
 * 
 * Example 2:
 * 
 * 
 * Given nums = [0,0,1,1,1,2,2,3,3,4],
 * 
 * Your function should return length = 5, with the first five elements of nums
 * being modified to 0, 1, 2, 3, and 4 respectively.
 * 
 * It doesn't matter what values are set beyond the returned length.
 * 
 * 
 * Clarification:
 * 
 * Confused why the returned value is an integer but your answer is an array?
 * 
 * Note that the input array is passed in by reference, which means
 * modification to the input array will be known to the caller as well.
 * 
 * Internally you can think of this:
 * 
 * 
 * // nums is passed in by reference. (i.e., without making a copy)
 * int len = removeDuplicates(nums);
 * 
 * // any modification to nums in your function would be known by the caller.
 * // using the length returned by your function, it prints the first len
 * elements.
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 * 
 */
#include <stdbool.h>
#include <string.h>

int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize == 0 || numsSize == 1)
    {
        return numsSize;
    }

    int index = 0;
    int currentNum = 0;
    while (true)
    {
        currentNum = nums[index];
        if (index != numsSize - 1 && nums[index + 1] == currentNum)
        {
            for (int i = index; i < numsSize - 1; i++)
            {
                if (nums[i + 1] != currentNum)
                {
                    memmove(nums + index + 1, nums + i + 1, (numsSize - i - 1) * sizeof(int));
                    numsSize -= i - index;
                    break;
                }

                if (i + 1 == numsSize - 1)
                {
                    numsSize = index + 1;
                    break;
                }
            }
        }
        index++;

        if (index == numsSize)
        {
            return index;
        }
    }
}

// int main()
// {
//     int arr[] = {1, 2,2};
//     removeDuplicates(arr, 3);
// }