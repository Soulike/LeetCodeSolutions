/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (46.86%)
 * Likes:    1745
 * Dislikes: 116
 * Total Accepted:    353.2K
 * Total Submissions: 743.3K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ret;
        map<string, int> stringToIndex;
        string originStr;

        for (string str : strs)
        {
            originStr = str;
            sort(str.begin(), str.end());
            auto iter = stringToIndex.find(str);
            if (iter == stringToIndex.end())
            {
                ret.push_back({});
                ret[ret.size() - 1].push_back(originStr);
                stringToIndex[str] = ret.size() - 1;
            }
            else
            {
                ret[iter->second].push_back(originStr);
            }
        }
        return ret;
    }
};
