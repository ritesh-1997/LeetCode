//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// maximum number of ways

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        long long int res[N+1][sum+1];
        
        memset(res,0,sizeof res);
        for(int i=1;i<=N;i++){
            res[i][0] = 1;
        }
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=sum;j++){
                if(coins[i-1]<=j){
                    
                    // adding as it needs number of ways.
                    res[i][j] = res[i][j-coins[i-1]]+res[i-1][j];
                }
                else{
                    res[i][j] = res[i-1][j];
                }
            }
        }
        
        return res[N][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends