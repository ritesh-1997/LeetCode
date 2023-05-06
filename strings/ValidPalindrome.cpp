class Solution {
public:
    bool isPalindrome(string s) {
        string ss = "";
        int size = s.length();

        for(int i = 0 ; i<s.size() ; i++) {
            if( (s[i]>='a'&& s[i]<='z') || (s[i]>='A'&& s[i]<='Z')  || (s[i]>='0'&& s[i]<='9')  ){
                ss+=tolower(s[i]);
            }
        }
        
        size = ss.size();
        int i = 0,j=size-1;
        
        while(i<j){
            if(ss[i++]!=ss[j--]){
                return false;
            }
        }
        return true;
    }
};