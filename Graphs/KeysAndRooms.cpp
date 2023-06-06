/**
 * There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0.
 * Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.
 *
 * When you visit a room, you may find a set of distinct keys in it. Each key has a number on it,
 * denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.
 *
 * Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i,
 * return true if you can visit all the rooms, or false otherwise.
 *
 * */

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int index = q.front();
            q.pop();
            if (visited[index])
            {
                continue;
            }

            visited[index] = 1;
            for (auto i : rooms[index])
            {
                q.push(i);
            }
        }

        for (auto i : visited)
        {
            if (i == 0)
            {
                return false;
            }
        }
        return true;
    }
};

class Solution
{
public:
    void dfs(vector<vector<int>> &rooms, vector<int> &visited, int current)
    {
        // make visited.
        visited[current] = 1;
        // traversal.
        for (int i = 0; i < rooms[current].size(); i++)
        {
            // if not visited call dfs.
            if (!visited[rooms[current][i]])
            {
                dfs(rooms, visited, rooms[current][i]);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<int> visited(n, 0);

        dfs(rooms, visited, 0);

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
                return false;
        }
        return true;
    }
};