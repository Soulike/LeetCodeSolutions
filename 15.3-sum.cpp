/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.03%)
 * Likes:    3929
 * Dislikes: 443
 * Total Accepted:    570.6K
 * Total Submissions: 2.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * firstTwoSum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ret;
        if (nums.size() < 3)
        {
            return ret;
        }

        sort(nums.begin(), nums.end());

        if (nums.front() > 0 || nums.back() < 0)
        {
            return ret;
        }

        int first = 0;
        int second = 1;
        int third = nums.size() - 1;

        for (first = 0; first <= nums.size() - 3 && third > first; first++)
        {
            third = nums.size() - 1;
            if (first > 0 && nums[first] == nums[first - 1]) // 重复，跳过不看
            {
                continue;
            }

            for (second = first + 1; second <= nums.size() - 2 && third > second; second++)
            {
                if (nums[first] + nums[second] > 0)
                {
                    break;
                }

                if (second > first + 1 && nums[second] == nums[second - 1]) // 重复，跳过不看
                {
                    continue;
                }

                while (nums[first] + nums[second] + nums[third] > 0)
                {
                    third--;
                    if(third <= second)
                    {
                        break;
                    }
                }

                if (nums[first] + nums[second] + nums[third] == 0 && third > second)
                {
                    ret.push_back({nums[first], nums[second], nums[third]});
                    third--;
                }
            }
        }

        return ret;
    }
};

// int main()
// {
//     Solution s;
//     s.threeSum(*(new vector<int>({1,2,-2,-1})));
// }