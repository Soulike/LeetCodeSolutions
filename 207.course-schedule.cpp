/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (37.90%)
 * Likes:    1867
 * Dislikes: 90
 * Total Accepted:    227.4K
 * Total Submissions: 594.3K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * Example 2:
 * 
 * 
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
 * 
 * Note:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 */
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        if (prerequisites.size() == 0)
        {
            return true;
        }

        set<int> removedNodes;
        map<int, int> nodeToInNumber; // 结点入度

        for (int i = 0; i < numCourses; i++)
        {
            nodeToInNumber[i] = 0;
        }

        for (int i = 0; i < prerequisites.size(); i++)
        {
            nodeToInNumber[prerequisites[i][1]]++;
        }

        bool found = true; // 是否这一轮找到了入度为 0 的结点

        while (found)
        {
            found = false;
            for (pair<int, int> p : nodeToInNumber)
            {
                if (!removedNodes.count(p.first) && p.second == 0)
                {
                    found = true;
                    removedNodes.insert(p.first);
                    for (int i = 0; i < prerequisites.size(); i++)
                    {
                        if (prerequisites[i].front() == p.first)
                        {
                            nodeToInNumber[prerequisites[i].back()]--;
                        }
                    }
                }
            }

            if (removedNodes.size() == numCourses)
            {
                return true;
            }
        }

        return false;
    }
};

// int main()
// {
//     Solution s;
//     vector<vector<int>> v = {{1, 0}};
//     s.canFinish(2, v);
// }