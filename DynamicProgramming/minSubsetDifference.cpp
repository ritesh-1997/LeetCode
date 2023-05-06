//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  
  // Return S1 sum;
    vector<int> ZeroOneKnapsackSubsetSum(int arr[],int n,int w){
        bool t[n+1][w+1];
        
        memset(t,false,sizeof t);
        
        for(int i=0;i<=n;i++){
            t[i][0] = true;
        }
        
        
        for(int i=1; i<=n; i++){
            for(int j=1;j<=w;j++){
                if(arr[i-1]<=j){
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j] ;
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        vector<int> res;
        
        for(int i = 0; i <= w/2 ;i++){
            if(t[n][i] == true){
                //cout<<i<<" ";
                res.push_back(i);
            }
        }
        //cout<<endl;
        return res;
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    /**
	     * S2-S1 = min  (1)
	     * S2+S1 = Range (2)
	     * S2 = Range-S1
	     * In (1)
	     * (Range-S1) - S1 = min
	     * Range - 2S1 = min
	     */
	     int sum = 0;
	     
	     for(auto i =0;i<n; i++){
	         sum += arr[i];
	     }
	     auto s1 = ZeroOneKnapsackSubsetSum(arr, n, sum);
	     
	     int mn = INT_MAX;
	     
	     for(int i=0;i<s1.size();i++){
	         mn = min(mn,sum-2*s1[i]);
	     }
	     return mn;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends