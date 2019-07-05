/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (42.20%)
 * Likes:    1706
 * Dislikes: 160
 * Total Accepted:    328.9K
 * Total Submissions: 773.7K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 * 
 * Note: You are not suppose to use the library's sort function for this
 * problem.
 * 
 * Example:
 * 
 * 
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * Follow up:
 * 
 * 
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 * 
 * 
 */
#include <vector>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        if(nums.size() < 2)
        {
            return;
        }

        const int RED = 0;
        const int WHITE = 1;
        const int BLUE = 2;

        int front = -1;
        int back = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            if (i >= back)
            {
                break;
            }
            
            if (nums[i] == RED)
            {
                front++;
                swap(nums[i], nums[front]);
            }
            else if (nums[i] == BLUE)
            {
                back--;
                swap(nums[i], nums[back]);
                i--;
            }
        }
    }

    void swap(int &a, int &b)
    {
        if (a != b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
    }
};
