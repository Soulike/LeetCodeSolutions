/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (30.55%)
 * Likes:    1116
 * Dislikes: 221
 * Total Accepted:    241.4K
 * Total Submissions: 783.6K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
#include <vector>
#include <set>
#include <algorithm>

using std::set;
using std::vector;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ret;

        if (nums.size() < 4)
        {
            return ret;
        }

        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        int sum = 0;
        for (int i = 0; i <= nums.size() - 4; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j <= nums.size() - 3; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                left = j + 1;
                right = nums.size() - 1;

                while (left < right)
                {
                    sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        ret.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1])
                        {
                            ++left;
                        }
                        while (left < right && nums[right] == nums[right - 1])
                        {
                            --right;
                        }
                        ++left;
                        --right;
                    }
                    else if (sum > target)
                    {
                        right--;
                    }
                    else
                    {
                        left++;
                    }
                }
            }
        }
        return ret;
    }
};