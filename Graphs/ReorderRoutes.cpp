/**
 * There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way
 * to travel between two different cities (this network form a tree). Last year, The ministry
 * of transport decided to orient the roads in one direction because they are too narrow.
 *
 * Roads are represented by connections where connections[i] = [ai, bi] represents a road
 * from city ai to city bi.
 *
 * This year, there will be a big event in the capital (city 0), and many people want to
 * travel to this city.
 *
 * Your task consists of reorienting some roads such that each city can visit the city 0.
 * Return the minimum number of edges changed.
 *
 * It's guaranteed that each city can reach city 0 after reorder.
 */

class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<pair<int, bool>>> adj_list(n);
        int cnt = 0;

        // reverse the connection in adj list.
        for (auto x : connections)
        {
            adj_list[x[0]].push_back({x[1], false});
            adj_list[x[1]].push_back({x[0], true});
        }

        queue<pair<int, bool>> q;
        q.push({0, true});
        vector<bool> vis(n, false);

        vis[0] = true;
        while (!q.empty())
        {
            int node = q.front().first;
            q.pop();
            for (int i = 0; i < adj_list[node].size(); i++)
            {
                // if node not visited and we cannot visit then inc count
                if (!vis[adj_list[node][i].first] && adj_list[node][i].second == false)
                {
                    cnt++;
                }

                // if not visted the make it true and push it into q
                if (!vis[adj_list[node][i].first])
                {
                    q.push(adj_list[node][i]);
                    vis[adj_list[node][i].first] = true;
                }
            }
        }
        return cnt;
    }
};