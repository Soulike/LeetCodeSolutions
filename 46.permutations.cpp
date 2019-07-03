/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (55.26%)
 * Likes:    2122
 * Dislikes: 63
 * Total Accepted:    394.3K
 * Total Submissions: 706.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
#include <vector>

using std::vector;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ret;

        if(nums.size() == 0)
        {
            return ret;
        }

        if (nums.size() == 1)
        {
            ret.push_back(nums);
            return ret;
        }

        int firstNum = nums[0];
        vector<int> restNums(nums.begin() + 1, nums.end());
        vector<vector<int>> restNumsPermutations = permute(restNums);
        vector<int> restNumsPermutation;
        restNumsPermutation.reserve(restNums.size());

        for (int i = 0; i < restNumsPermutations.size(); i++)
        {
            restNumsPermutation = restNumsPermutations[i];
            for (int j = 0; j <= restNumsPermutation.size(); j++)
            {
                restNumsPermutation.insert(
                    restNumsPermutation.begin() + j,
                    firstNum);
                ret.push_back(restNumsPermutation);
                restNumsPermutation = restNumsPermutations[i];
            }
        }

        return ret;
    }
};
