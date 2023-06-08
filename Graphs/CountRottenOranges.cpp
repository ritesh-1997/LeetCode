/**
 * You are given an m x n grid where each cell can have one of three values:
 *
 * 0 representing an empty cell,
 * 1 representing a fresh orange, or
 * 2 representing a rotten orange.
 *
 * Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
 *
 *
 * Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this
 * is impossible, return -1.
 *
 * */

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        vector<int> dx = {0, 1, -1, 0}, dy = {1, 0, 0, -1};
        int m = grid.size(), n = grid[0].size();

        // Queue will store the index of all rotten oranges
        queue<pair<int, int>> rotten;

        int oranges = 0, count = 0, res = 0;

        for (auto i = 0; i < m; i++)
        {
            for (auto j = 0; j < n; j++)
            {
                // rotten
                if (grid[i][j] == 2)
                    rotten.push({i, j});

                // counting oranges
                if (grid[i][j] != 0)
                    oranges++;
            }
        }

        while (!rotten.empty())
        {
            int size = rotten.size();

            // counting rotten oranges by processing them at times.
            count += size;
            // process all rotten oranges present in queue at once as
            // it will inject all nearby oranges
            while (size--)
            {
                auto p = rotten.front();
                int i = p.first;
                int j = p.second;
                rotten.pop();
                for (int move = 0; move < 4; move++)
                {
                    int x = i + dx[move];
                    int y = j + dy[move];
                    // if outside boundary or not fresh
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1)
                    {
                        continue;
                    }
                    rotten.push({x, y});
                    // making it rotten
                    grid[x][y] = 2;
                }
            }
            // only after processing all the rotten oranges present in queue
            //
            if (!rotten.empty())
                res++;
        }
        return count == oranges ? res : -1;
    }
};