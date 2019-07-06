/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (29.27%)
 * Likes:    2192
 * Dislikes: 103
 * Total Accepted:    219K
 * Total Submissions: 742.6K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        int *maxProducts = new int[2];
        int *minProducts = new int[2];
        maxProducts[0] = minProducts[0] = nums[0];
        int maximum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                maxProducts[i % 2] = minProducts[i % 2] = 0;
            }
            else
            {
                maxProducts[i % 2] = max(nums[i], maxProducts[(i - 1) % 2] * nums[i], minProducts[(i - 1) % 2] * nums[i]);
                minProducts[i % 2] = min(nums[i], maxProducts[(i - 1) % 2] * nums[i], minProducts[(i - 1) % 2] * nums[i]);
                maximum = maxProducts[i % 2] > maximum ? maxProducts[i % 2] : maximum;
            }
        }

        delete[] maxProducts;
        delete[] minProducts;

        return maximum;
    }

    int max(int a, int b, int c)
    {
        return a > b ? (a > c ? a : c) : (b > c ? b : c);
    }

    int min(int a, int b, int c)
    {
        return a < b ? (a < c ? a : c) : (b < c ? b : c);
    }
};
