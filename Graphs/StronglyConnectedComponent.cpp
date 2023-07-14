/**
 * Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges,
 * Find the number of strongly connected components in the graph
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find number of strongly connected components in the graph.

    // topological sort
    void topologicalSort(vector<vector<int>> adj, vector<bool> &visited, int u, stack<int> &st)
    {
        visited[u] = 1;
        for (auto v : adj[u])
        {
            if (!visited[v])
                topologicalSort(adj, visited, v, st);
        }
        st.push(u);
    }

    vector<vector<int>> reverseGraph(vector<vector<int>> adj, int V)
    {
        vector<vector<int>> g(V, vector<int>());
        for (int u = 0; u < V; u++)
        {
            for (auto v : adj[u])
            {
                g[v].push_back(u);
            }
        }
        return g;
    }

    // dfs
    void dfs(vector<vector<int>> &g, vector<bool> &visited, int u)
    {
        visited[u] = true;
        for (auto i : g[u])
        {
            if (!visited[i])
            {
                dfs(g, visited, i);
            }
        }
    }

    int kosaraju(int V, vector<vector<int>> &adj)
    {
        // code here
        vector<bool> visited(V, false);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                topologicalSort(adj, visited, i, st);
        }
        // reversing the graph
        auto g = reverseGraph(adj, V);
        int cnt = 0;
        for (int i = 0; i < V; i++)
            visited[i] = false;
        while (!st.empty())
        {
            int top = st.top();
            st.pop();

            if (!visited[top])
            {
                dfs(g, visited, top);
                cnt++;
            }
        }

        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends