/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (42.43%)
 * Likes:    1551
 * Dislikes: 198
 * Total Accepted:    245.1K
 * Total Submissions: 570.9K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example, given the following tree:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 
 * The flattened tree should look like:
 * 
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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
#include<vector>

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
private:
    vector<TreeNode *> nodes;
public:
    void flatten(TreeNode *root)
    {
        if(root == NULL)
        {
            return;
        }

        dfs(root);
        for (int i = 0; i < nodes.size() - 1;i++)
        {
            nodes[i]->left = NULL;
            nodes[i]->right = nodes[i + 1];
        }
    }

    void dfs(TreeNode* root)
    {
        nodes.push_back(root);
        if(root->left != NULL)
        {
            dfs(root->left);
        }
        if(root->right != NULL)
        {
            dfs(root->right);
        }
    }
};
