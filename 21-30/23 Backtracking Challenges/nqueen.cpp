#include <iostream>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n)
{
    //check column
    for (int row = 0; row < i; row++)
    {
        if (board[row][j] == 1)
        {
            return false;
        }
    }
    //check left diagonal
    int x = i;
    int y = j;
    while (x >= 0 and y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }
    //check right diagonal
    x = i;
    y = j;
    while (x >= 0 and y < n)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y++;
    }
    return true;
}

bool nQueen(int board[][10], int i, int n, int &cnt)
{
    //we are filling row wise and i is the row index
    //base case
    if (i == n)
    {
        //count
        cnt++;
        return false;
    }
    //recursive case
    //iterate over the rows
    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, i, j, n))
        {
            board[i][j] = 1;
            bool queenrakhpaye = nQueen(board, i + 1, n, cnt);
            if (queenrakhpaye)
            {
                return true;
            }
            //if queenrakhpaye is false then we need to backtrack and undo the changes
            board[i][j] = 0;
        }
    }
    //You have tried for all positions sbut couldn't place the queen
    return false;
}

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    int board[10][10] = {0};
    nQueen(board, 0, n, cnt);
    cout << cnt;
    return 0;
}