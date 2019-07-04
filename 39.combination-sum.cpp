/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (48.62%)
 * Likes:    2114
 * Dislikes: 65
 * Total Accepted:    357.5K
 * Total Submissions: 726.7K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
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
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        return combinationSum(candidates, 0, target);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int left, int target)
    {
        vector<vector<int>> ret;
        vector<vector<int>> recursiveRet;

        if (target < candidates[left])
        {
            return ret;
        }

        for (int i = left; i < candidates.size(); i++)
        {
            if (candidates[i] == target)
            {
                ret.push_back({candidates[i]});
            }
            else if (target - candidates[i] >= candidates[left])
            {
                recursiveRet = combinationSum(candidates, i, target - candidates[i]);
                for (auto &ret : recursiveRet)
                {
                    ret.push_back(candidates[i]);
                }
                ret.insert(ret.end(), recursiveRet.cbegin(), recursiveRet.cend());
            }
        }
        return ret;
    }
};

// int main()
// {
//     Solution s;
//     vector<int> v = {7,3,9,6};
//     s.combinationSum(v, 6);
// }
