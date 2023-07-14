/**
 * Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is
 *  a path possible from the source to destination. You can traverse up, down, right and left.
 *
 * The description of cells is as follows:
 *
 * A value of cell 1 means Source.
 * A value of cell 2 means Destination.
 * A value of cell 3 means Blank cell.
 * A value of cell 0 means Wall.
 * Note: There are only a single source and a single destination.
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>> &grid)
    {
        // code here
        queue<vector<int>> q;
        int dir[5] = {0, 1, 0, -1, 0};

        int n = grid.size(), m = grid[0].size();
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    grid[i][j] = 0;
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag)
        {
            return 0;
        }
        while (!q.empty())
        {
            auto top = q.front();
            int i = top[0], j = top[1];
            q.pop();
            // cout<<i<<" -- "<<j<<endl;
            if (grid[i][j] == 2)
            {
                return 1;
            }

            for (int x = 0; x < 4; x++)
            {
                int dx = i + dir[x];
                int dy = j + dir[x + 1];

                if (dx >= 0 && dx < n && dy >= 0 && dy < m && (grid[dx][dy] != 0))
                {
                    // cout<<dx<<" "<<dy<<" "<<grid[dx][dy]<<endl;
                    if (grid[dx][dy] == 2)
                    {
                        return 1;
                    }
                    grid[dx][dy] = 0; // making wall or visited
                    q.push({dx, dy});
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        bool ans = obj.is_Possible(grid);
        cout << ((ans) ? "1\n" : "0\n");
    }
    return 0;
}
// } Driver Code Ends