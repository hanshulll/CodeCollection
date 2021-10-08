// Program to find the maximum profit when tradiing in a stock

// PROBLEM STATEMENT

/*
    You are given an array prices where prices[i] is the price of a given stock on the ith day.

    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.   

    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>&prices);

// Driver Code

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i=0;i<n;i++)
    {
        cin >> prices[i];
    }

    cout << maxProfit(prices) << endl;;
}

// Implemented function for the solution.

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int minPriceSoFar = INT32_MAX;  // Stores the minimum price of a stock till the selling day
    int maxProfit = INT32_MIN;      // Stores the final answer of maximum profit.

    for(int i=0;i<n;i++)
    {
        minPriceSoFar = min(minPriceSoFar,prices[i]);
        int profit = prices[i] - minPriceSoFar;    //  Stores the profit for each day after selling.
        maxProfit = max(maxProfit,profit);
    }
    return maxProfit;
}