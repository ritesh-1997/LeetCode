/**
 * https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
 *
 * Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit
 * if you are currently in this cell. The sign of grid[i][j] can be:
 *
 * 1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
 * 2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
 * 3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
 * 4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
 * Notice that there could be some signs on the cells of the grid that point outside the grid.
 *
 * You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that
 * starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following
 * the signs on the grid. The valid path does not have to be the shortest.
 *
 * You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.
 *
 * Return the minimum cost to make the grid have at least one valid path.
 */

class Solution
{
public:
    int minCost(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
        dist[0][0] = 0;
        // dist,i,j
        pq.push({0, 0, 0});
        vector<int> dir = {0, 1, 0, -1, 0};
        map<pair<int, int>, int> mp;
        mp[{0, 1}] = 1;
        mp[{0, -1}] = 2;
        mp[{1, 0}] = 3;
        mp[{-1, 0}] = 4;
        while (!pq.empty())
        {
            vector<int> top = pq.top();
            pq.pop();
            int i = top[1], j = top[2], cost = top[0];
            // if destination reached
            if (i == row - 1 && j == col - 1)
            {
                return dist[i][j];
            }
            if (dist[i][j] < cost)
            {
                continue;
            }
            // traverse in all direction
            for (int x = 0; x < 4; x++)
            {
                int dx = i + dir[x];
                int dy = j + dir[x + 1];
                if (dx >= 0 && dx < row && dy >= 0 && dy < col)
                {
                    int intermediatecost = 0;
                    // if current direction is not then add cost
                    if (grid[i][j] != mp[{dir[x], dir[x + 1]}])
                    {
                        intermediatecost = 1;
                    }
                    int currCost = intermediatecost + cost;
                    if (currCost < dist[dx][dy])
                    {
                        dist[dx][dy] = currCost;
                        pq.push({currCost, dx, dy});
                    }
                }
            }
        }
        return dist[row - 1][col - 1];
    }
};