//{ Driver Code Starts
// Initial Template for C++
/**
 * Initial
 * Given an array of lowercase strings A[] of size N, determine if the strings
 *  can be chained together to form a circle.
 * A string X can be chained together with another string Y if the last character
 * of X is same as first character of Y. If every string of the array can be chained
 * with exactly two strings of the array(one with the first character and second with
 * the last character of the string), it will form a circle.
 *
 * For example, for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be
 * Yes as the given strings can be chained as "for", "rig", "geek" and "kaf"
 *
 */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void dfs(vector<int> adj[], int node, vector<bool> &visited)
    {
        visited[node] = true;
        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                dfs(adj, i, visited);
            }
        }
    }
    bool isConnected(int s, vector<int> adj[], vector<bool> &mark)
    {
        vector<bool> visited(26, false);
        dfs(adj, s, visited);
        for (int i = 0; i < 26; i++)
        {
            if (!visited[i] && mark[i])
            {
                return false;
            }
        }
        return true;
    }
    int isCircle(int N, vector<string> A)
    {
        // code here
        vector<int> indegree(26, 0), outdegree(26, 0);
        vector<bool> mark(26, false);
        vector<int> adj[26];

        for (auto str : A)
        {
            int n = str.size();
            int u = str[0] - 'a';
            int v = str[n - 1] - 'a';
            mark[u] = mark[v] = true;
            indegree[v]++;
            outdegree[u]++;
            adj[u].push_back(v);
        }
        for (int i = 0; i < 26; i++)
        {
            if (indegree[i] != outdegree[i])
            {
                return false;
            }
        }
        return isConnected(A[0][0] - 'a', adj, mark);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++)
        {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends