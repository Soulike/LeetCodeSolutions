/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (43.48%)
 * Likes:    2338
 * Dislikes: 48
 * Total Accepted:    418.9K
 * Total Submissions: 957.9K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
#include <algorithm>
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
    bool isSymmetric(TreeNode *root)
    {
        queue<TreeNode *> queue;
        int queueSize;
        TreeNode *front;

        queue.push(root);

        while (!queue.empty())
        {
            if (!queueIsSymmetric(queue))
            {
                return false;
            }

            queueSize = queue.size();
            for (int i = 0; i < queueSize; i++)
            {
                front = queue.front();
                queue.pop();
                if (front != NULL)
                {
                    queue.push(front->left);
                    queue.push(front->right);
                }
            }
        }

        return true;
    }

    static bool queueIsSymmetric(queue<TreeNode *> q)
    {
        vector<TreeNode *> v;
        while (!q.empty())
        {
            v.push_back(q.front());
            q.pop();
        }
        vector<TreeNode *>::const_iterator front = v.cbegin();
        vector<TreeNode *>::const_iterator back = v.cend() - 1;

        while (front < back)
        {
            if ((*front) != NULL && (*back) != NULL && (*front)->val != (*back)->val)
            {
                return false;
            }
            else if ((*front) == NULL && (*back) != NULL)
            {
                return false;
            }
            else if ((*front) != NULL && (*back) == NULL)
            {
                return false;
            }
            else
            {
                front++;
                back--;
            }
        }
        return true;
    }
};
