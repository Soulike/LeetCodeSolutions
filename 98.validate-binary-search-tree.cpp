/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (25.75%)
 * Likes:    2056
 * Dislikes: 300
 * Total Accepted:    422.7K
 * Total Submissions: 1.6M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * Input: [2,1,3]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 
 * Input: [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    bool isValid = true;

public:
    bool isValidBST(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }

        dfs(root, root);

        return isValid;
    }

    void dfs(TreeNode* root, TreeNode* currentRoot)
    {
        if(currentRoot == NULL)
        {
            return;
        }

        if(isValidNode(root, currentRoot) == false)
        {
            isValid = false;
            return;
        }
        dfs(root, currentRoot->left);
        dfs(root, currentRoot->right);
    }

    bool isValidNode(TreeNode *root, TreeNode *node)
    {
        if (root == node)
        {
            return true;
        }
        else if(root != node && root->val == node->val)
        {
            return false;
        }
        else if (root->val > node->val)
        {
            if (root->left != NULL)
            {
                return isValidNode(root->left, node);
            }
            else
            {
                return false;
            }
        }
        else // root->val < node->val
        {
            if (root->right != NULL)
            {
                return isValidNode(root->right, node);
            }
            else
            {
                return false;
            }
        }
    }
};
