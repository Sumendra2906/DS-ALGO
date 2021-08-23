#include <iostream>
using namespace std;

bool ratInMaze(char maze[][1005], int sol[][1005], int i, int j, int m, int n)
{
    //base case
    if (i == m - 1 and j == n - 1)
    {
        sol[i][j] = 1;
        //print
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        return true;
    }

    //check rat is inside the maze
    if (i > m - 1 or j > n - 1)
    {
        return false;
    }

    //check path is not blocked
    if (maze[i][j] == 'X')
    {
        return false;
    }
    //assume that path is available
    sol[i][j] = 1;
    //check right and down
    bool rightSuccess = ratInMaze(maze, sol, i, j + 1, m, n);
    bool downSuccess;
    if (!rightSuccess)
    {
        downSuccess = ratInMaze(maze, sol, i + 1, j, m, n);
    }
    //backtracking
    //set all 1s to 0s
    sol[i][j] = 0;

    if (rightSuccess or downSuccess)
    {
        return true;
    }
    return false;
}

int main()
{
    int m, n;
    cin >> m >> n;
    char maze[1005][1005];
    for (int i = 0; i < m; i++)
    {
        cin >> maze[i];
    }
    int sol[1005][1005] = {0};
    if (ratInMaze(maze, sol, 0, 0, m, n) == false)
    {
        cout << -1;
    }
    ratInMaze(maze, sol, 0, 0, m, n);
    return 0;
}