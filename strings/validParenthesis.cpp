class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int i = 0;i<s.length();i++){
            //cout<<s[i]<<" ";
            if(s[i] == '('|| s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
                //cout<<" 1 top " << st.top()<<endl;
            }
            else if((s[i] == ')'|| s[i] == ']' || s[i] == '}') && st.empty()){
                return false;
            }
            else if((s[i]==')' && st.top() == '(') || (s[i]=='}' && st.top() == '{') || (s[i]==']' && st.top() == '[')){
                //cout<< " top " << st.top()<<endl;
                st.pop();
            }
            else
                return false;
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};