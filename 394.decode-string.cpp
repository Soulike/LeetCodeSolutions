/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (44.92%)
 * Likes:    1554
 * Dislikes: 88
 * Total Accepted:    109.8K
 * Total Submissions: 242.4K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * Examples:
 * 
 * 
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 * 
 * 
 * 
 * 
 */
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> numStack;
        stack<string> stringStack;
        string buildingString;

        stringStack.push("");

        int numberBuilder = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] - '0' >= 0 && s[i] - '0' <= 9) // 是数字的一位
            {
                numberBuilder = numberBuilder * 10 + s[i] - '0';
            }
            else if (s[i] == '[')   // 数字读取完成，压入数字栈
            {
                numStack.push(numberBuilder);
                stringStack.push("");
                numberBuilder = 0;
            }
            else if (s[i] == ']') // 字符串读取完成
            {
                int num = numStack.top();
                numStack.pop();
                string str = stringStack.top();
                stringStack.pop();
                stringStack.top() += multipyString(str, num);
            }
            else // 是字母，添加到栈顶
            {
                stringStack.top() += s[i];
            }
        }
        return stringStack.top();
    }

    string multipyString(const string& s, int num)
    {
        string newStr;
        for (int i = 0; i < num; i++)
        {
            newStr += s;
        }
        return newStr;
    }
};
