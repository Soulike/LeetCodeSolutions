/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 *
 * https://leetcode.com/problems/counting-bits/description/
 *
 * algorithms
 * Medium (64.72%)
 * Likes:    1451
 * Dislikes: 110
 * Total Accepted:    174.9K
 * Total Submissions: 268.9K
 * Testcase Example:  '2'
 *
 * Given a non negative integer number num. For every numbers i in the range 0
 * ≤ i ≤ num calculate the number of 1's in their binary representation and
 * return them as an array.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: [0,1,1]
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: [0,1,1,2,1,2]
 * 
 * 
 * Follow up:
 * 
 * 
 * It is very easy to come up with a solution with run time
 * O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a
 * single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like
 * __builtin_popcount in c++ or in any other language.
 * 
 */
#include <vector>

using namespace std;

// https://www.cnblogs.com/grandyang/p/5294255.html
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> res = {0};
        for (int i = 1; i <= num; ++i)
        {
            if (i % 2 == 0)
                res.push_back(res[i / 2]);
            else
                res.push_back(res[i / 2] + 1);
        }
        return res;
    }
};