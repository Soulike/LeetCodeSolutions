/*
 * @lc app=leetcode id=29 lang=c
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.15%)
 * Likes:    696
 * Dislikes: 3301
 * Total Accepted:    201.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero.
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * 
 * Note:
 * 
 * 
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 2^31 − 1 when the
 * division result overflows.
 * 
 * 
 */
#include <stdbool.h>
#include <stdint.h>

int abs(int a)
{
    if (a < 0)
    {
        return -a;
    }
    else
    {
        return a;
    }
}

int divide(int dividend, int divisor)
{
    if (divisor == 1)
    {
        return dividend;
    }

    if (divisor == -1)
    {
        if (dividend != INT32_MIN)
        {
            return -dividend;
        }
        else
        {
            return INT32_MAX;
        }
    }

    if (divisor == INT32_MIN)
    {
        if (dividend == INT32_MIN)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int res = 0;
    bool isPositive = true;
    if (dividend < 0 || divisor < 0)
    {
        isPositive = false;
    }

    if (dividend < 0 && divisor < 0)
    {
        isPositive = true;
    }

    divisor = abs(divisor);

    if (dividend == INT32_MIN)
    {
        dividend = INT32_MAX - divisor + 1;
        res++;
    }

    dividend = abs(dividend);

    if (divisor > dividend && res == 0)
    {
        return 0;
    }

    if (divisor == dividend)
    {
        return isPositive ? 1 : -1;
    }

    int k = 0; // 2^k

    while (dividend - divisor >= divisor)
    {
        divisor <<= 1;
        k++;
    }

    while (k >= 0)
    {
        if (dividend - divisor >= 0)
        {
            res += 1 << k;
            dividend -= divisor;
        }
        divisor >>= 1;
        k--;
    }

    return isPositive ? res : -res;
}