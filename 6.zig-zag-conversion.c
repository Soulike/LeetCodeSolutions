/*
 * @lc app=leetcode id=6 lang=c
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (31.90%)
 * Likes:    1061
 * Dislikes: 3307
 * Total Accepted:    327.6K
 * Total Submissions: 1M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */

#include <stdlib.h>
#include <string.h>

char *convert(char *s, int numRows)
{
    if (numRows == 1 || s[0] == '\0')
    {
        return s;
    }

    int len = strlen(s);
    int groupNum = len / (numRows + numRows - 2);
    int numCols = groupNum * (numRows - 1);
    int reminder = len % (numRows + numRows - 2);
    if (reminder >= numRows)
    {
        numCols += reminder / numRows;
        numCols += reminder % numRows;
    }
    else if (reminder > 0)
    {
        numCols++;
    }

    char(*arr)[numCols] = (char(*)[numCols])malloc(numRows * numCols * sizeof(char));

    memset(arr, '\0', numRows * numCols * sizeof(char));

    int currentIndex = 0;

    for (int col = 0; col < numCols; col++)
    {
        reminder = col % (numRows - 1);
        if (reminder == 0)
        {
            for (int row = 0; row < numRows; row++)
            {
                if (currentIndex >= len)
                {
                    break;
                }
                arr[row][col] = s[currentIndex++];
            }
        }
        else
        {
            arr[numRows - 1 - reminder][col] = s[currentIndex++];
        }
    }

    currentIndex = 0;

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            if (arr[i][j] != '\0')
            {
                s[currentIndex++] = arr[i][j];
            }
        }
    }

    free(arr);

    return s;
}
