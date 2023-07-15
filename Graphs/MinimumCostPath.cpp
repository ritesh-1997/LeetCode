/**
 *
 * Given a square grid of size N, each cell of which contains integer cost which
 * represents a cost to traverse through that cell, we need to find a path from
 * top left cell to bottom right cell by which the total cost incurred is minimum.
 *
 * From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j).
 *
 *
 * Note: It is assumed that negative cost cycles do not exist in the input matrix.
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    int minimumCostPath(vector<vector<int>> &grid)
    {
        // Code here
        int n = grid.size(), m = grid[0].size();
        int dir[5] = {0, 1, 0, -1, 0};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> weight(n, vector<int>(m, INT_MAX - 10000));

        pq.push({grid[0][0], 0, 0});
        weight[0][0] = grid[0][0];

        while (!pq.empty())
        {
            auto top = pq.top();
            int cost = top[0], i = top[1], j = top[2];
            pq.pop();
            if (cost > weight[i][j])
            {
                continue;
            }
            if (i == n - 1 && j == m - 1)
            {
                return weight[i][j];
            }
            for (int x = 0; x < 4; x++)
            {
                int dx = i + dir[x];
                int dy = j + dir[x + 1];
                if (dx >= 0 && dx < n && dy >= 0 && dy < m)
                {
                    if (cost + grid[dx][dy] < weight[dx][dy])
                    {
                        weight[dx][dy] = cost + grid[dx][dy];
                        pq.push({weight[dx][dy], dx, dy});
                    }
                }
            }
        }
        return weight[n - 1][m - 1];
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
        int ans = obj.minimumCostPath(grid);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends