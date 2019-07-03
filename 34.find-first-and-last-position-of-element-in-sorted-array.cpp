/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (33.59%)
 * Likes:    1661
 * Dislikes: 89
 * Total Accepted:    313.4K
 * Total Submissions: 928.6K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */
#include <vector>

using std::vector;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ret;
        ret.push_back(leftBinarySearch(nums, 0, nums.size() - 1, target));
        ret.push_back(rightBinarySearch(nums, 0, nums.size() - 1, target));
        return ret;
    }

    // 在搜索到后，查看左边，如果左边元素也匹配，就向左边转移，直到左边元素不匹配
    // [left, right]
    int leftBinarySearch(const vector<int> &nums, int left, int right, int target)
    {
        if (right < left)
        {
            return -1;
        }

        if (left == right)
        {
            return nums[left] == target ? left : -1;
        }

        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            if (mid == left)
            {
                return left;
            }

            if (nums[mid - 1] == target)
            {
                return leftBinarySearch(nums, left, mid - 1, target);
            }
            else
            {
                return mid;
            }
        }
        else if (nums[mid] > target) // 向左
        {
            return leftBinarySearch(nums, left, mid - 1, target);
        }
        else // 向右
        {
            return leftBinarySearch(nums, mid + 1, right, target);
        }
    }

    // 在搜索到后，查看右边，如果右边元素也匹配，就向右边转移，直到右边元素不匹配
    // [left, right]
    int rightBinarySearch(const vector<int> &nums, int left, int right, int target)
    {
        if (right < left)
        {
            return -1;
        }

        if (left == right)
        {
            return nums[left] == target ? left : -1;
        }

        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            if (mid == right)
            {
                return right;
            }

            if (nums[mid + 1] == target)
            {
                return rightBinarySearch(nums, mid + 1, right, target);
            }
            else
            {
                return mid;
            }
        }
        else if (nums[mid] > target) // 向左
        {
            return rightBinarySearch(nums, left, mid - 1, target);
        }
        else // 向右
        {
            return rightBinarySearch(nums, mid + 1, right, target);
        }
    }
};
