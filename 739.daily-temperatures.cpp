/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (60.03%)
 * Likes:    1349
 * Dislikes: 36
 * Total Accepted:    72.7K
 * Total Submissions: 120.9K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 
 * Given a list of daily temperatures T, return a list such that, for each day
 * in the input, tells you how many days you would have to wait until a warmer
 * temperature.  If there is no future day for which this is possible, put 0
 * instead.
 * 
 * For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76,
 * 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 * 
 * 
 * Note:
 * The length of temperatures will be in the range [1, 30000].
 * Each temperature will be an integer in the range [30, 100].
 * 
 */
#include <vector>

using std::vector;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        vector<int> day(T.size(), 0);
        
        for (int i = T.size() - 2; i >= 0; i--)
        {
            if (T[i] > T[i + 1])
            {
                int pos = i + 1;

                while (true)
                {
                    pos = pos + day[pos];
                    if (T[pos] > T[i])
                    {
                        day[i] = pos - i;
                        break;
                    }
                    if (day[pos] == 0)
                    {
                        day[i] = 0;
                        break;
                    }
                }
            }
            else if (T[i] == T[i + 1])
            {
                if(day[i+1] == 0)
                {
                    day[i] = 0;
                }
                else
                {
                    day[i] = day[i + 1] + 1;
                }
            }
            else if (T[i] < T[i + 1])
            {
                day[i] = 1;
            }
        }
        return day;
    }
};
