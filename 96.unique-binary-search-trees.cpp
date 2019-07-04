/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (46.28%)
 * Likes:    1784
 * Dislikes: 68
 * Total Accepted:    205.3K
 * Total Submissions: 440K
 * Testcase Example:  '3'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ... n?
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */
// 卡特兰数
#include<cstring>
class Solution
{
public:
    int numTrees(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }

        int num[n + 1];
        memset(num, 0, (n + 1) * sizeof(int));
        num[0] = num[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                num[i] += num[j] * num[i - 1 - j];
            }
        }

        return num[n];
    }
};
