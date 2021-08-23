#include <iostream>
#include <cmath>
using namespace std;

bool canPlace(int board[][10], int i, int j, int num, int n)
{
    for (int x = 0; x < n; x++)
    {
        if (board[i][x] == num or board[x][j] == num)
        {
            //checking row and colum
            return false;
        }
    }
    //checking submatrix
    int rn = sqrt(n);
    int sx = (i / rn) * rn;
    int sy = (j / rn) * rn;
    for (int x = sx; x < sx + rn; x++)
    {
        for (int y = sy; y < sy + rn; y++)
        {
            if (board[x][y] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int board[][10], int i, int j, int n)
{
    //base case
    if (i == n)
    {
        //rows are over
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                cout << board[row][col] << " ";
            }
            cout << endl;
        }
        return true;
    }
    if (j == n)
    {
        //current row is over go to next row
        return solveSudoku(board, i + 1, 0, n);
    }
    if (board[i][j] != 0)
    {
        //it is already filled up
        return solveSudoku(board, i, j + 1, n);
    }
    //recursive case
    //iterate over all the numbers
    for (int num = 1; num <= n; num++)
    {
        if (canPlace(board, i, j, num, n))
        {
            board[i][j] = num;
            bool canSolve = solveSudoku(board, i, j + 1, n);
            if (canSolve)
            {
                return true;
            }
        }
    }
    //backtracking
    board[i][j] = 0;
    return false;
}

int main()
{
    int n;
    cin >> n;
    int board[10][10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    solveSudoku(board, 0, 0, n);
    return 0;
}