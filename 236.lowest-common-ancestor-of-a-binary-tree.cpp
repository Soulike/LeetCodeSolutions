/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (37.36%)
 * Likes:    2038
 * Dislikes: 138
 * Total Accepted:    291.4K
 * Total Submissions: 766.9K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given
 * nodes in the tree.
 * 
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of itself).”
 * 
 * Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant
 * of itself according to the LCA definition.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All of the nodes' values will be unique.
 * p and q are different and both values will exist in the binary tree.
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
#include <string>
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
private:
    vector<TreeNode *> preOrderSeq;
    vector<TreeNode *> inOrderSeq;

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        preOrder(root);
        inOrder(root);
        return lowestCommonAncestor(p, q, 0, preOrderSeq.size() - 1, 0, inOrderSeq.size() - 1);
    }

    TreeNode *lowestCommonAncestor(TreeNode *p, TreeNode *q, int preLeft, int preRight, int inLeft, int inRight)
    {
        TreeNode *root = preOrderSeq[preLeft];
        int rootInInOrderSeqIndex = 0;
        int pInInOrderSeqIndex = 0;
        int qInInOrderSeqIndex = 0;
        // 找到根、p 和 q 在中序遍历序列的位置
        for (int i = inLeft; i <= inRight; i++)
        {
            if (inOrderSeq[i] == root)
            {
                rootInInOrderSeqIndex = i;
            }

            if (inOrderSeq[i] == p)
            {
                pInInOrderSeqIndex = i;
            }

            if (inOrderSeq[i] == q)
            {
                qInInOrderSeqIndex = i;
            }
        }

        int leftTreeLength = rootInInOrderSeqIndex - inLeft;
        int rightTreeLength = inRight + 1 - rootInInOrderSeqIndex;

        if (p == root)
        {
            return p;
        }
        else if (q == root)
        {
            return q;
        }
        else if ((pInInOrderSeqIndex - rootInInOrderSeqIndex) * (qInInOrderSeqIndex - rootInInOrderSeqIndex) < 0)
        {
            return root;
        }
        else if (pInInOrderSeqIndex - rootInInOrderSeqIndex < 0) // 左半边
        {
            return lowestCommonAncestor(p, q, preLeft + 1, preLeft + leftTreeLength + 1, inLeft, inLeft + leftTreeLength);
        }
        else // 右半边
        {
            return lowestCommonAncestor(p, q, preLeft + leftTreeLength + 1, preRight, inLeft + leftTreeLength + 1, inRight);
        }
    }

    void preOrder(TreeNode *root)
    {
        if (root != NULL)
        {
            preOrderSeq.push_back(root);
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void inOrder(TreeNode *root)
    {
        if (root != NULL)
        {
            inOrder(root->left);
            inOrderSeq.push_back(root);
            inOrder(root->right);
        }
    }
};
