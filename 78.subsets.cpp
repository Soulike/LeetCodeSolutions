/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (52.90%)
 * Likes:    2036
 * Dislikes: 52
 * Total Accepted:    380K
 * Total Submissions: 710.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        if(nums.size() < 1)
        {
            return {{}};
        }
        auto ret =  subsets(nums, 0);
        ret.push_back({});
        return ret;
    }

    vector<vector<int>> subsets(vector<int> &nums, int left)
    {
        if (left == nums.size() - 1)
        {
            return {
                {nums[left]}};
        }

        vector<vector<int>> ret;

        vector<vector<int>> partSubSets = subsets(nums, left + 1);

        ret.insert(ret.end(), partSubSets.begin(), partSubSets.end());

        for (vector<int> subset : partSubSets)
        {
            subset.push_back(nums[left]);
            ret.push_back(subset);
        }

        ret.push_back({nums[left]});

        return ret;
    }
};

// int main()
// {
//     Solution s;
//     vector<int> v = {1, 2, 3};
//     s.subsets(v);
// }
