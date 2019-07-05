/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (31.31%)
 * Likes:    1853
 * Dislikes: 92
 * Total Accepted:    294.9K
 * Total Submissions: 933K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (word.size() == 0)
        {
            return false;
        }

        bool got = false;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    board[i][j] = '\0';
                    if (word.size() == 1)
                    {
                        return true;
                    }
                    else
                    {
                        got = got || exist(board, i, j, word.substr(1));
                    }
                    board[i][j] = word[0];
                }
            }
        }
        return got;
    }

    // rowIndex, colIndex 指示上一次匹配的地方
    bool exist(vector<vector<char>> &board, int rowIndex, int colIndex, string word)
    {
        if (word.size() == 1)
        {
            return (
                (rowIndex - 1 >= 0 && board[rowIndex - 1][colIndex] == word[0]) ||
                (rowIndex + 1 < board.size() && board[rowIndex + 1][colIndex] == word[0]) ||
                (colIndex - 1 >= 0 && board[rowIndex][colIndex - 1] == word[0]) ||
                (colIndex + 1 < board[rowIndex].size() && board[rowIndex][colIndex + 1] == word[0]));
        }

        if (rowIndex < 0 || rowIndex >= board.size() || colIndex < 0 || colIndex >= board[rowIndex].size())
        {
            return false;
        }

        int got = false;
        string subStr = word.substr(1);

        if (rowIndex - 1 >= 0 && board[rowIndex - 1][colIndex] == word[0])
        {
            board[rowIndex - 1][colIndex] = '\0';
            got = got || exist(board, rowIndex - 1, colIndex, subStr);
            board[rowIndex - 1][colIndex] = word[0];
        }

        if (rowIndex + 1 < board.size() && board[rowIndex + 1][colIndex] == word[0])
        {
            board[rowIndex + 1][colIndex] = '\0';
            got = got || exist(board, rowIndex + 1, colIndex, subStr);
            board[rowIndex + 1][colIndex] = word[0];
        }

        if (colIndex - 1 >= 0 && board[rowIndex][colIndex - 1] == word[0])
        {
            board[rowIndex][colIndex - 1] = '\0';
            got = got || exist(board, rowIndex, colIndex - 1, subStr);
            board[rowIndex][colIndex - 1] = word[0];
        }

        if (colIndex + 1 < board[rowIndex].size() && board[rowIndex][colIndex + 1] == word[0])
        {
            board[rowIndex][colIndex + 1] = '\0';
            got = got || exist(board, rowIndex, colIndex + 1, subStr);
            board[rowIndex][colIndex + 1] = word[0];
        }

        return got;
    }
};

// int main()
// {
//     Solution s;
//     vector<vector<char>> v = { { 'C', 'A', 'A' }, { 'A', 'A', 'A' }, { 'B', 'C', 'D' } };

//     s.exist(v, "AAB");
// }