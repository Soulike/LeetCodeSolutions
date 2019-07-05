/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (35.66%)
 * Likes:    2191
 * Dislikes: 166
 * Total Accepted:    364.1K
 * Total Submissions: 1M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() < 2)
        {
            return intervals;
        }

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ret;
        ret.push_back(intervals.front());

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].front() <= ret.back().back())
            {
                ret.back().back() = ret.back().back() > intervals[i].back() ? ret.back().back() : intervals[i].back();
            }
            else
            {
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};