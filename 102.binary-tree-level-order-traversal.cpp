/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (48.55%)
 * Likes:    1555
 * Dislikes: 42
 * Total Accepted:    393.1K
 * Total Submissions: 801.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
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
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;

        if(root == NULL)
        {
            return ret;
        }

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
            ret.push_back(numVector);
            numVector.clear();
        }

        return ret;
    }
};
