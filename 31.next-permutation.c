/*
 * @lc app=leetcode id=31 lang=c
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (30.49%)
 * Likes:    1855
 * Dislikes: 581
 * Total Accepted:    245.7K
 * Total Submissions: 802K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

int* merge(int *a, int aSize, int *b, int bSize)
{
    int *merged = (int *)malloc((aSize + bSize) * sizeof(int));
    int currentIndex = 0;
    int aIndex = 0;
    int bIndex = 0;
    while (aIndex < aSize && bIndex < bSize)
    {
        merged[currentIndex++] = a[aIndex] < b[bIndex] ? a[aIndex++] : b[bIndex++];
    }

    if (aIndex == aSize)
    {
        memcpy(merged + currentIndex, b + bIndex, (bSize - bIndex) * sizeof(int));
    }
    else if (bIndex == bSize)
    {
        memcpy(merged + currentIndex, a + aIndex, (aSize - aIndex) * sizeof(int));
    }
    return merged;
}

void mergeSort(int *a, int size)
{
    if (size > 1)
    {
        int mid = size / 2;
        mergeSort(a, mid);
        mergeSort(a + mid, size - mid);
        int *merged = merge(a, mid, a + mid, size - mid);
        memcpy(a, merged, size * sizeof(int));
        free(merged);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
1. 从末尾向前看，找到第一个不满足递增的元素位置 index
2. 如果 index 到 0 仍满足，直接对数组排序
3. 从 index 往后看，找到第一个小于等于 index 元素的位置 index2（或数组末尾）
4. index2--，定位到最小的大于 index 元素的位置
5. 交换 index 与 index2 的元素
6. 对 index+1 到末尾进行排序
 */

void nextPermutation(int *nums, int numsSize)
{
    int index = numsSize - 2;
    while (index >= 0 && nums[index] - nums[index + 1] >= 0)
    {
        index--;
    }
    if(index == -1)
    {
        mergeSort(nums, numsSize);
    }
    else
    {
        int index2 = numsSize;
        for (int i = index+1; i < numsSize;i++)
        {
            if(nums[i] <= nums[index])
            {
                index2 = i;
                break;
            }
        }
        index2--;
        swap(&nums[index], &nums[index2]);
        mergeSort(nums + index + 1, numsSize - index - 1);
    }
}
