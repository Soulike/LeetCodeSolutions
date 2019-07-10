/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (45.26%)
 * Likes:    1446
 * Dislikes: 68
 * Total Accepted:    100.8K
 * Total Submissions: 222.1K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * ⁠
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.  
 * 
 * 
 * Example 1:
 * 
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 * Explanation: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array is positive and will not exceed 20. 
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 * 
 * 
 */
#include <vector>

using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        return findTargetSumWays(nums, 0, S);
    }

    int findTargetSumWays(vector<int> &nums, int left, long long S)
    {
        if (left == nums.size() - 1)
        {
            if (S == nums[left] && S == -nums[left])
            {
                return 2;
            }
            else if (S == nums[left] || S == -nums[left])
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int plusRet = findTargetSumWays(nums, left + 1, S - nums[left]);
        int minusRet = findTargetSumWays(nums, left + 1, S + nums[left]);

        return plusRet + minusRet;
    }
};
