//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int bfs(vector<int> &t, map<int, int> &mp, int node)
    {
        if (node >= 30)
        {
            return 0;
        }
        if (t[node] != -1)
        {
            return t[node];
        }
        int min_val = INT_MAX;

        // for dice movement
        for (int i = 1; i <= 6; i++)
        {
            int dist = node + i;
            // finding dist in map, if present then
            if (mp.count(dist) > 0)
            {
                if (mp[dist] < dist)
                {
                    continue;
                }
                dist = mp[dist];
            }
            min_val = min(min_val, bfs(t, mp, dist) + 1);
        }
        return t[node] = min_val;
    }
    int minThrow(int N, int arr[])
    {
        // code here
        vector<int> dp(31, -1);
        map<int, int> mp;
        for (int i = 0; i < 2 * N; i += 2)
        {
            mp[arr[i]] = arr[i + 1];
        }
        return bfs(dp, mp, 1);
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
        int arr[2 * N];
        for (int i = 0; i < 2 * N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.minThrow(N, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends