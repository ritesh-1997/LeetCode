/**
 * Given a 2D binary matrix A(0-based index) of dimensions NxM.
 * Find the minimum number of steps required to reach from (0,0) to (X, Y).
 *
 * Note: You can only move left, right, up and down, and only through cells that contain 1.
 */
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int dir[5] = {0, 1, 0, -1, 0};
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
    {
        // code here
        vector<vector<int>> vis(N, vector<int>(M, 0));
        queue<vector<int>> pq;
        if (!A[0][0])
        {
            return -1;
        }
        pq.push({0, 0, 0});
        vis[0][0] = 1;
        while (!pq.empty())
        {
            auto top = pq.front();
            pq.pop();
            int i = top[1], j = top[2], cost = top[0];
            if (i == X && j == Y)
            {
                return cost;
            }
            // traverse in all distance
            for (int x = 0; x < 4; x++)
            {
                int dx = i + dir[x];
                int dy = j + dir[x + 1];
                if (dx >= 0 && dx < N && dy >= 0 && dy < M && A[dx][dy] && !vis[dx][dy])
                {
                    vis[dx][dy] = 1;
                    pq.push({cost + 1, dx, dy});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends