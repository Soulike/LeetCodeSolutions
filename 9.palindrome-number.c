/*
 * @lc app=leetcode id=9 lang=c
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (43.40%)
 * Likes:    1424
 * Dislikes: 1299
 * Total Accepted:    585.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */

#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

bool isPalindrome(int x)
{
    if (x < 0) // impossible when x is negative
    {
        return false;
    }

    if (x == 0)
    {
        return true;
    }

    // 答案算法，缺点是如果 x 是 long long 就不能用了，y 有溢出风险
    // int xCopy = x;
    // long y = 0;

    // while (xCopy > 0)
    // {
    //     y *= 10;
    //     y += xCopy % 10;
    //     xCopy /= 10;
    // }

    // return x == y;

    int numberLength = 0; // x 的位数

    while (true)
    {
        if (x / (int)pow(10, numberLength) < 1)
        {
            break;
        }
        else
        {
            numberLength++;
        }
    }

    int *numbers = (int *)malloc(numberLength * sizeof(int));

    for (int i = 0; i < numberLength; i++)
    {
        numbers[i] = (x % (int)pow(10, i + 1)) / (int)pow(10, i);
    }

    bool isPalindrome = true;

    for (int i = 0; i < numberLength; i++)
    {
        if (numbers[i] != numbers[numberLength - i - 1])
        {
            isPalindrome = false;
            break;
        }
    }

    free(numbers);
    return isPalindrome;
}