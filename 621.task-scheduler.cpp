/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 *
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (45.47%)
 * Likes:    1709
 * Dislikes: 293
 * Total Accepted:    90.6K
 * Total Submissions: 198.1K
 * Testcase Example:  '['A','A','A','B','B','B']\n2'
 *
 * Given a char array representing tasks CPU need to do. It contains capital
 * letters A to Z where different letters represent different tasks. Tasks
 * could be done without original order. Each task could be done in one
 * interval. For each interval, CPU could finish one task or just be idle.
 * 
 * However, there is a non-negative cooling interval n that means between two
 * same tasks, there must be at least n intervals that CPU are doing different
 * tasks or just be idle.
 * 
 * You need to return the least number of intervals the CPU will take to finish
 * all the given tasks.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: tasks = ['A','A','A','B','B','B'], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 * 
 * 
 */
// https://www.cnblogs.com/grandyang/p/7098764.html
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> time(26, 0);
        for (char task : tasks)
        {
            time[task - 'A']++;
        }
        sort(time.begin(), time.end());
        int i = 25, mx = time[25], len = tasks.size();
        while (i >= 0 && time[i] == mx)
            --i;
        return max(len, (mx - 1) * (n + 1) + 25 - i);
    };
};