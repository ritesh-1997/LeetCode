/**
 * 
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * 
 * You want to maximize your profit by choosing a single day to buy one stock and choosing a 
 * different day in the future to sell that stock.
 * 
 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 * 
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),max_profit = 0;
        vector<int> res(n,0);
        res[n-1] = prices[n-1];
        for(int i = n-2 ; i>=0 ; i--){
            res[i] = max(prices[i],res[i+1]);
        }

        for(int i=0;i<n;i++){
            max_profit = max(max_profit,res[i]-prices[i]);
        }
        return max_profit;
    }
};