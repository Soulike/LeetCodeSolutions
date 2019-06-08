/*
 * @lc app=leetcode id=12 lang=c
 *
 * [12] Integer to Roman
 *
 * https://leetcode.com/problems/integer-to-roman/description/
 *
 * algorithms
 * Medium (50.99%)
 * Likes:    589
 * Dislikes: 1859
 * Total Accepted:    232.5K
 * Total Submissions: 455.5K
 * Testcase Example:  '3'
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
 * Given an integer, convert it to a roman numeral. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * 
 * Input: 3
 * Output: "III"
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "IV"
 * 
 * Example 3:
 * 
 * 
 * Input: 9
 * Output: "IX"
 * 
 * Example 4:
 * 
 * 
 * Input: 58
 * Output: "LVIII"
 * Explanation: L = 50, V = 5, III = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: 1994
 * Output: "MCMXCIV"
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 */

#include <stdlib.h>
#include <string.h>

struct CharArray
{
    char *array;
    int size;
    int capacity;
};

typedef struct CharArray CharArray;

CharArray *createCharArray()
{
    CharArray *charArray = (CharArray *)malloc(sizeof(CharArray));
    charArray->array = (char *)malloc(10 * sizeof(char));
    charArray->size = 0;
    charArray->capacity = 10;
    return charArray;
}

void destroyCharArray(CharArray *charArray)
{
    free(charArray->array);
    free(charArray);
}

void expand(CharArray *charArray)
{
    char *newArray = (char *)malloc(charArray->capacity * 2 * sizeof(char));
    memcpy(newArray, charArray->array, charArray->size * sizeof(char));
    free(charArray->array);
    charArray->array = newArray;
    charArray->capacity *= 2;
}

void push(CharArray *charArray, char element)
{
    if (charArray->capacity == charArray->size)
    {
        expand(charArray);
    }
    charArray->array[charArray->size++] = element;
}

char *toString(CharArray *charArray)
{
    char *str = (char *)malloc((charArray->size + 1) * sizeof(char));
    memcpy(str, charArray->array, charArray->size * sizeof(char));
    str[charArray->size] = '\0';
    return str;
}

char *intToRoman(int num)
{
    int thousandAmount = num / 1000;
    num %= 1000;
    int hundredAmount = num / 100;
    num %= 100;
    int tenAmound = num / 10;
    num %= 10;
    int numAmount = num;

    CharArray *charArray = createCharArray();

    for (int i = 0; i < thousandAmount; i++)
    {
        push(charArray, 'M');
    }

    while (hundredAmount >= 9)
    {
        push(charArray, 'C');
        push(charArray, 'M');
        hundredAmount -= 9;
    }

    while(hundredAmount >= 5)
    {
        push(charArray, 'D');
        hundredAmount -= 5;
    }

    while (hundredAmount >= 4)
    {
        push(charArray, 'C');
        push(charArray, 'D');
        hundredAmount -= 4;
    }

    while(hundredAmount > 0)
    {
        push(charArray, 'C');
        hundredAmount--;
    }

    while (tenAmound >= 9)
    {
        push(charArray, 'X');
        push(charArray, 'C');
        tenAmound -= 9;
    }

    while (tenAmound >= 5)
    {
        push(charArray, 'L');
        tenAmound -= 5;
    }

    while (tenAmound >= 4)
    {
        push(charArray, 'X');
        push(charArray, 'L');
        tenAmound -= 4;
    }

    while (tenAmound > 0)
    {
        push(charArray, 'X');
        tenAmound--;
    }

    while (numAmount >= 9)
    {
        push(charArray, 'I');
        push(charArray, 'X');
        numAmount -= 9;
    }

    while (numAmount >= 5)
    {
        push(charArray, 'V');
        numAmount -= 5;
    }

    while (numAmount >= 4)
    {
        push(charArray, 'I');
        push(charArray, 'V');
        numAmount -= 4;
    }

    while (numAmount > 0)
    {
        push(charArray, 'I');
        numAmount--;
    }

    char* ret = toString(charArray);

    destroyCharArray(charArray);

    return ret;
}
