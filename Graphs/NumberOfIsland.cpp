//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int dx[8] = {1, 1, -1, -1, 0, 1, 0, -1};
    int dy[8] = {1, -1, 1, -1, 1, 0, -1, 0};
    bool isSafe(int i, int j, int m, int n, vector<vector<char>> &grid)
    {
        return i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == '1';
    }
    // Function to find the number of islands.
    void dfs(vector<vector<char>> &grid, int i, int j, int m, int n)
    {
        grid[i][j] = '0';
        for (int x = 0; x < 8; x++)
        {
            if (isSafe(i + dx[x], j + dy[x], m, n, grid))
                dfs(grid, i + dx[x], j + dy[x], m, n);
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j, m, n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends