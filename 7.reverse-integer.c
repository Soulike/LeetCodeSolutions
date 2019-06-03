/*
 * @lc app=leetcode id=7 lang=c
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.32%)
 * Likes:    2173
 * Dislikes: 3305
 * Total Accepted:    697.7K
 * Total Submissions: 2.8M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */

#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

int reverse(int x)
{
    int isNegativeMax = x == INT32_MIN; // ????????????????????????????????
    if (isNegativeMax)
    {
        x += 1;
    }

    int absX = abs(x); // ???????

    int numbers[10] = {0}; // ???????10 ???????????? 0

    int numberLength = 0; // ?????

    int lastNumber = 0; // ????????

    // ??????
    for (int i = 1; i <= 10 && absX > 0; i++)
    {
        lastNumber = absX % (int)pow(10, i);
        numbers[i - 1] = lastNumber / (int)pow(10, i - 1);
        absX -= lastNumber;
        numberLength = i;
    }

    int reversedX = 0;
    int numToAdd = 0;

    for (int i = 0; i < 10; i++)
    {
        if (numbers[i] == 0)
        {
            continue;
        }
        else
        {
            if (numberLength - i - 1 == 9 && numbers[i] > 2) // ??????
            {
                return 0;
            }
            numToAdd = numbers[i] * (int)pow(10, numberLength - i - 1);
            if (INT32_MAX - reversedX < numToAdd) // ???????????????
            {
                return 0;
            }
            reversedX += numbers[i] * (int)pow(10, numberLength - i - 1);
        }
    }

    return x > 0 ? reversedX : isNegativeMax ? -1 * reversedX - 1 : -1 * reversedX;
}
