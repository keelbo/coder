#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool checkValIsValid(vector<vector<char>> &board, int p, int q, char val)
{
    // check row
    for (int j = 0; j < 9; j++)
    {
        cout << val << " " << board[p][j] << endl;
        if (val == board[p][j])
        {
            return false;
        }
    }

    // check col
    for (int j = 0; j < 9; j++)
    {
        if (val == board[j][q])
        {
            return false;
        }
    }

    // check box
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (val == board[3 * (p / 3) + i][3 * (q / 3) + j])
            {
                return false;
            }
        }
    }
    return true;
}

bool solve(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                for (char k = '1'; k <= '9'; k = k + 1)
                {
                    cout << k << endl;
                    if (checkValIsValid(board, i, j, k))
                    {
                        board[i][j] = k;
                        if (solve(board))
                        {
                            return true;
                        }
                        else
                        {
                            // ACCIDENT
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}

int main(int argc, char const *argv[])
{
    vector<vector<char>> board{
        vector<char>{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        vector<char>{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        vector<char>{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        vector<char>{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        vector<char>{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        vector<char>{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        vector<char>{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        vector<char>{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        vector<char>{'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(board);

    return 0;
}
