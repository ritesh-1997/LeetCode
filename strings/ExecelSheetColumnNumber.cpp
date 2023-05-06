class Solution {
public:
    int titleToNumber(string columnTitle) {
        int size = columnTitle.length(),val=0;
        for(int i = 0;i<size ; i++){
            val += ((columnTitle[i]-'A'+1)*pow(26,size-(i+1)));
        }
        return val;
    }
};