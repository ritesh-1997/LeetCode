//{ Driver Code Starts
/**
 * Given an array arr[ ] of length N consisting cost of N toys and an integer
 * K depicting the amount with you. Your task is to find maximum number of
 * toys you can buy with K amount.
 */
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int toyCount(int N, int K, vector<int> arr)
    {
        // code here
        int cnt = 0;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < N; i++)
        {

            K -= arr[i];
            cnt++;
            if (K < 0)
            {
                return cnt - 1;
            }
            else if (K == 0)
            {
                break;
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
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.toyCount(N, K, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends