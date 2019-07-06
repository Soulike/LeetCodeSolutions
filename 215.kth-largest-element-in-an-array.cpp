/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (47.85%)
 * Likes:    2131
 * Dislikes: 178
 * Total Accepted:    391.7K
 * Total Submissions: 808.7K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */
#include <vector>

using namespace std;

// 快速查找
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        if (nums.size() == 1)
        {
            return nums.front();
        }
        return quickSearch(nums, 0, nums.size() - 1, k);
    }

    int quickSearch(vector<int> &nums, int left, int right, int k) // [left, right]
    {
        int leftIndex = left + 1;
        int rightIndex = right;
        int p = nums[left];
        while (true)
        {
            while (leftIndex <= right && nums[leftIndex] > p)
            {
                leftIndex++;
            }

            while (rightIndex > left && nums[rightIndex] <= p)
            {
                rightIndex--;
            }

            if (leftIndex >= rightIndex || left > right || right <= left)
            {
                break;
            }

            swap(nums[leftIndex], nums[rightIndex]);
        }

        if (rightIndex - left == k - 1)
        {
            return nums[left];
        }
        else // rightIndex != k-1
        {
            swap(nums[left], nums[rightIndex]);
            if (k - 1 < rightIndex - left) // 左半边
            {
                return quickSearch(nums, left, rightIndex - 1, k);
            }
            else // k-1 > rightIndex - left  右半边
            {
                return quickSearch(nums, rightIndex + 1, right, k - (rightIndex - left) - 1);
            }
        }
    }

    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
};
