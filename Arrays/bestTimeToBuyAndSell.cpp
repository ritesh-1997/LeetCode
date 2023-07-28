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

#include <bits/stdc++.h>
using namespace std;

// function to calculate max profit for a given stock
int maxProfit(vector<int> &prices, int n)
{
    int max_profit = 0;
    vector<int> res(n, 0);
    res[n - 1] = prices[n - 1];
    // calculate the max profit from right
    for (int i = n - 2; i >= 0; i--)
    {
        res[i] = max(prices[i], res[i + 1]);
    }

    // max profit comparision
    for (int i = 0; i < n; i++)
    {
        max_profit = max(max_profit, res[i] - prices[i]);
    }
    return max_profit;
}

// Main Code Starts.

int main()
{
    int n;
    // input the number days
    cout << "Enter the number of days : ";
    cin >> n;
    vector<int> prices;
    // input the stock price for each day till n
    cout << "\nEnter the price of stock for each day : \n";
    for (int i = 0; i < n; i++)
    {
        int price;
        cin >> price;
        prices.push_back(price);
    }

    cout << "\nMax profit is : " << maxProfit(prices, n) << endl;
    return 0;
}
