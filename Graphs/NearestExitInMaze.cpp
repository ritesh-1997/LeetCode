/**
 * You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.')
 * and walls (represented as '+'). You are also given the entrance of the maze, where
 * entrance = [entrancerow, entrancecol] denotes the row and column of the cell you
 * are initially standing at.
 *
 * In one step, you can move one cell up, down, left, or right. You cannot step into
 * a cell with a wall, and you cannot step outside the maze. Your goal is to find the
 * nearest exit from the entrance. An exit is defined as an empty cell that is at the
 * border of the maze. The entrance does not count as an exit.
 *
 * Return the number of steps in the shortest path from the entrance to the nearest exit,
 * or -1 if no such path exists.
 */

class Solution
{
public:
    bool isValid(int i, int j, int m, int n)
    {
        return i >= 0 and j >= 0 and i < m and j < n;
    }
    int bfs(vector<vector<char>> &maze, int i, int j, int m, int n)
    {
        vector<int> dx = {0, -1, 1, 0}, dy = {1, 0, 0, -1};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        vis[i][j] = true;
        q.push({i, j});
        int res = 0;
        while (!q.empty())
        {
            int s = q.size();
            // one movement for all direction stored in q.
            while (s--)
            {
                auto curr = q.front();
                q.pop();
                if ((curr.first != i || curr.second != j) && (curr.first == 0 || curr.second == 0 || curr.first == m - 1 || curr.second == n - 1))
                {
                    return res;
                }
                for (int id = 0; id < 4; id++)
                {
                    int x = curr.first + dx[id];
                    int y = curr.second + dy[id];
                    if (isValid(x, y, m, n) && !vis[x][y] && maze[x][y] == '.')
                    {
                        vis[x][y] = true;
                        q.push({x, y});
                    }
                }
            }
            res++;
        }
        return -1;
    }
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int m = maze.size(), n = maze[0].size();
        int i = entrance[0], j = entrance[1];
        if (maze[i][j] == '+')
        {
            return -1;
        }

        return bfs(maze, i, j, m, n);
    }
};