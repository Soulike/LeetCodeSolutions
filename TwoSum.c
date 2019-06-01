

/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *result = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;
    int found = 0;  // 是否已经找到

    for (int i = 0; i < numsSize && found == 0; i++)
    {
        for (int j = i + 1; j < numsSize && found == 0; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                found = 1;
            }
        }
    }
    return result;
}
