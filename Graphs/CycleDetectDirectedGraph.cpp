//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool dfs(vector<int> adj[], int node, vector<bool> &visited, vector<bool> &rec)
    {
        if (!visited[node])
        {
            visited[node] = true;
            rec[node] = true;
            for (auto i : adj[node])
            {
                if (!visited[i])
                {
                    if (dfs(adj, i, visited, rec))
                    {
                        return true;
                    }
                }
                else if (rec[i])
                {
                    return true;
                }
            }
        }
        return rec[node] = false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<bool> visited(V, false), rec(V, false);
        for (auto i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(adj, i, visited, rec))
                {
                    return true;
                }
            }
        }
        return false;
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

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends