/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (31.93%)
 * Likes:    2027
 * Dislikes: 201
 * Total Accepted:    275.3K
 * Total Submissions: 857.2K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 */
#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return true;
        }
        if (nums[0] == 0)
        {
            return false;
        }
        bool canGetOver = true;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == 0)
            {
                canGetOver = false;
                for (int j = i - 1; j >= 0; j--)
                {
                    if (nums[j] > i - j)
                    {
                        canGetOver = true;
                        break;
                    }
                }
                if (canGetOver == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
