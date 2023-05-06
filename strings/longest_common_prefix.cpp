//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string findprefix(string str1,string str2){
        
        int size = min(str1.length(),str2.length());
        string result = "";

        for(int i=0 ; i<size ; i++){

            if(str1[i] != str2[i])
                break;
            result += str1[i];
        }
        return result;
    }

    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if(size == 0){
            return "";
        }
        else if(size == 1){
            return strs[0];
        }

        string prefix = strs[0];
        for(int i = 1 ; i<size ; i++){
            prefix = findprefix(prefix,strs[i]);   
        }
        return prefix;
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
        cout << obj.longestCommonPrefix(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends