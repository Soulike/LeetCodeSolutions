/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (41.19%)
 * Likes:    1798
 * Dislikes: 50
 * Total Accepted:    232.4K
 * Total Submissions: 556.8K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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

#include <cstdio>
#include <vector>

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0)
        {
            return NULL;
        }
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode *buildTree(vector<int> &preorder, int preOrderLeft, int preOrderRight, vector<int> &inorder, int inOrderLeft, int inOrderRight)
    {
        TreeNode *root = new TreeNode(preorder[preOrderLeft]);
        if (preOrderRight == preOrderLeft)
        {
            root->left = NULL;
            root->right = NULL;
            return root;
        }
        int inOrderRootIndex = 0;
        for (int i = inOrderLeft; i <= inOrderRight; i++)
        {
            if (inorder[i] == root->val)
            {
                int leftTreeSize = i - inOrderLeft;
                int rightTreeSize = inOrderRight - i;
                if (leftTreeSize > 0)
                {
                    root->left = buildTree(preorder, preOrderLeft + 1, preOrderLeft + leftTreeSize, inorder, inOrderLeft, i - 1);
                }
                else
                {
                    root->left = NULL;
                }

                if (rightTreeSize > 0)
                {
                    root->right = buildTree(preorder, preOrderLeft + leftTreeSize + 1, preOrderRight, inorder, i + 1, inOrderRight);
                }
                else
                {
                    root->right = NULL;
                }
            }
        }
        return root;
    }
};
