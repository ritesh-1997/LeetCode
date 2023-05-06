//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long int
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    ll mergesort(ll arr[],ll temp[], ll start, ll mid,ll end){
        ll i = start, j = mid, k=start, inv_cnt = 0;
        while(i<=(mid-1) && j<=end){
            if(arr[i]<=arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
                
                // since a[i] is > a[j] which is after mid
                inv_cnt += (mid-i);
            }
        }
        while(i<=mid-1){
            temp[k++] = arr[i++];
        }
        while (j<=end){
            temp[k++]= arr[j++];
        }
        for(i=start;i<=end;i++){
            arr[i] = temp[i];
        }
        return inv_cnt;
    }
    
    ll merge(ll arr[], ll temp[], ll start, ll end){
        ll mid,inv_cnt = 0;
        if(start<end){
            
            mid = start+(end-start)/2;
            inv_cnt += merge(arr,temp,start,mid);
            inv_cnt += merge(arr,temp,mid+1,end);
            
            inv_cnt += mergesort(arr,temp,start,mid+1,end);
        }
        return inv_cnt;
        
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        
        ll temp[N];
        
        return merge(arr,temp,0,N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends