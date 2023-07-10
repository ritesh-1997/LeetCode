/**
 * You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
 *
 * Note: Use a recursive approach to find the DFS traversal of the graph starting from the 0th
 * vertex from left to right according to the graph.
 *
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void dfs(vector<int> adj[], int i, vector<bool> &visited, vector<int> &res)
    {
        visited[i] = true;
        res.push_back(i);
        for (auto j : adj[i])
        {

            if (!visited[j])
                dfs(adj, j, visited, res);
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> visited(V, false);
        vector<int> res;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs(adj, i, visited, res);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends