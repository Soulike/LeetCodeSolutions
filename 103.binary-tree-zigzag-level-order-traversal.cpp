/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (41.81%)
 * Likes:    1012
 * Dislikes: 60
 * Total Accepted:    228.1K
 * Total Submissions: 540.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <cstdlib>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;

        if (root == NULL)
        {
            return ret;
        }

        int level = 0;
        queue<TreeNode *> nodeQueue;
        vector<int> numVector;

        nodeQueue.push(root);

        int queueSize = 0;

        TreeNode *queueFront = NULL;

        while (!nodeQueue.empty())
        {
            queueSize = nodeQueue.size();
            for (int i = 0; i < queueSize; i++)
            {
                queueFront = nodeQueue.front();
                numVector.push_back(queueFront->val);
                nodeQueue.pop();

                if (queueFront->left != NULL)
                {
                    nodeQueue.push(queueFront->left);
                }

                if (queueFront->right != NULL)
                {
                    nodeQueue.push(queueFront->right);
                }
            }
            if (level % 2 != 0)
            {
                reverse(numVector.begin(), numVector.end());
            }

            ret.push_back(numVector);
            numVector.clear();
            level++;
        }

        return ret;
    }
};