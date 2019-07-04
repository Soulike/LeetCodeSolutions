/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (41.69%)
 * Likes:    876
 * Dislikes: 47
 * Total Accepted:    228.9K
 * Total Submissions: 543K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
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
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
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
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        return combinationSum2(candidates, 0, target);
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int left, int target)
    {
        vector<vector<int>> ret;
        vector<vector<int>> recursiveRet;

        if (candidates.size() == 0)
        {
            return ret;
        }

        if (left > candidates.size() - 1)
        {
            return ret;
        }

        if (target < candidates[left])
        {
            return ret;
        }

        for (int i = left; i < candidates.size(); i++)
        {
            if (i > left && candidates[i] == candidates[i - 1])
            {
                continue;
            }

            if (candidates[i] == target)
            {
                ret.push_back({candidates[i]});
            }
            else if (target - candidates[i] >= candidates[left])
            {
                recursiveRet = combinationSum2(candidates, i + 1, target - candidates[i]);
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