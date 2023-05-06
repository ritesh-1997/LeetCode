class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr;
        if(numRows == 1){
            vector<int> temp;
            temp.push_back(1);
            arr.push_back(temp);
        }
        else if(numRows == 2){
            vector<int> temp;
            temp.push_back(1);
            arr.push_back(temp);
            vector<int> temp1;
            temp1.push_back(1);
            temp1.push_back(1);
            arr.push_back(temp1);
        }
        else{
            vector<int> temp;
            temp.push_back(1);
            arr.push_back(temp);
            vector<int> temp1;
            temp1.push_back(1);
            temp1.push_back(1);
            arr.push_back(temp1);
            for(int i = 3;i<=numRows;i++){
                vector<int> temp(i,1);
                for(int j=1;j<i-1;j++){
                    temp[j] = arr[i-2][j-1] + arr[i-2][j];
                }
                arr.push_back(temp);
            }
        }
        return arr;
        
    }
};