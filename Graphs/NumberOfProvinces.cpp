/**
 * There are n cities. Some of them are connected, while some are not. If city a is connected directly with
 * city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
 *
 * A province is a group of directly or indirectly connected cities and no other cities outside of the group.
 *
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city
 * are directly connected, and isConnected[i][j] = 0 otherwise.
 *
 * Return the total number of provinces.
 */
class Solution
{
public:
    void dfs(vector<vector<int>> &isConnected, vector<int> &visited, int index)
    {
        visited[index] = 1;
        // traversing all the connected component of index
        for (auto i = 0; i < isConnected[index].size(); i++)
        {

            if (isConnected[index][i] && !visited[i])
            {
                dfs(isConnected, visited, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int cnt = 0;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(isConnected, visited, i);
                cnt++;
            }
        }
        return cnt;
    }
};