class Solution {
public:
    
    int characterReplacement(string s, int k) {
        int i = 0,j=0,res = 0,max_same_char = 0;
        int n = s.size();
        vector<int> hash(26,0);
        for(int j=0;j<n;j++){

            // finding index of current character
            int c = s[j]-'A';

            // hashing for count of characters
            hash[c]++;

            // finding max of same character which will be used
            // to find the window size
            max_same_char = max(max_same_char,hash[c]);

            
            // hash[c] : current character count 
            // j-i+1 is distance 
            // final is total distinct character apart 
            // from current character.
            int diff_char = (j-i+1) - max_same_char;

            if(diff_char>k){
                // revoming first character from substring
                // or sliding window.
                hash[s[i]-'A']--;
                // increment the i to make i near to k
                i++;
            }
            res = max(res,(j-i)+1);

        }
        return res;
    }
};