//Subarray with given sum

// Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        long long sum = 0;
        int start = 0, end = n-1;
        vector<int> result;
        
        sum = arr[start];
        if(sum == s){
            result.push_back(1);
            result.push_back(1);
            return result;
        }
        for(int i = 1;i<n ; i++){
            
            if(sum+arr[i]<= s){
                sum += arr[i];
            }
            else{
                sum += arr[i];
                
                while(sum>s){
                    sum -= arr[start];
                    start++;
                }
            }
            if(sum == s && start<=i){
                result.push_back(start+1);
                result.push_back(i+1);
                return result;
            }
        }

        result.push_back(-1);
        return result;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends