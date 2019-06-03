/*
 * @lc app=leetcode id=13 lang=c
 *
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (52.42%)
 * Likes:    1250
 * Dislikes: 2642
 * Total Accepted:    419.6K
 * Total Submissions: 800.3K
 * Testcase Example:  '"III"'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 * 
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 * 
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * 
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * 
 * Input: "III"
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: "IV"
 * Output: 4
 * 
 * Example 3:
 * 
 * 
 * Input: "IX"
 * Output: 9
 * 
 * Example 4:
 * 
 * 
 * Input: "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 */

#include <string.h>

int getNumber(char);

int romanToInt(char *s)
{
    int length = strlen(s);
    if (length == 1) // 如果只有一个，那就直接查表返回
    {
        return getNumber(s[0]);
    }

    int beforeNumber = 0; // 当前处理字符前一个对应数字
    int sum = 0;
    int currentNumber = 0;

    for (int i = 0; i < length; i++)
    {
        currentNumber = getNumber(s[i]);
        sum += currentNumber;
        if (i != 0 && beforeNumber < currentNumber) // 前一个数比现在这个数小，那么应该减去前一个数
        {
            sum = sum - 2 * beforeNumber;
        }
        beforeNumber = currentNumber;
    }

    return sum;
}

int getNumber(char c) // 从罗马数字获得对应整数
{
    switch (c)
    {
    case 'I':
    {
        return 1;
    }
    case 'V':
    {
        return 5;
    }
    case 'X':
    {
        return 10;
    }
    case 'L':
    {
        return 50;
    }
    case 'C':
    {
        return 100;
    }
    case 'D':
    {
        return 500;
    }
    case 'M':
    {
        return 1000;
    }
    default:
    {
        return 0;
    }
    }
}
