/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (56.72%)
 * Likes:    1705
 * Dislikes: 72
 * Total Accepted:    479.7K
 * Total Submissions: 838.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
#include <vector>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        if (root == NULL)
        {
            return ret;
        }

        stack<TreeNode *> nodeStack;
        TreeNode *currentNode = root;

        while (currentNode != NULL || !nodeStack.empty())
        {
            if (currentNode != NULL)
            {
                nodeStack.push(currentNode);
                currentNode = currentNode->left;
            }
            else //currentNode == NULL
            {
                currentNode = nodeStack.top();
                nodeStack.pop();
                ret.push_back(currentNode->val);

                currentNode = currentNode->right;
            }
        }
        return ret;
    }
};
