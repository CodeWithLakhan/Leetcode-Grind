class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size(); 
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
       int ans = solve( n-1 ,  amount , coins , dp);
       return ans>=1e9? -1:ans;
    }
    int solve( int i , int amount , vector<int>& arr ,vector<vector<int>>& dp)
    {
        if(i==0)
        {
            if(amount % arr[i] == 0) return amount/arr[i];
            else return 1e9;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];

        int nottake = 0 + solve(i-1,amount,arr,dp);
        int take = INT_MAX;
        if(arr[i]<=amount) take = 1 + solve(i,amount-arr[i],arr,dp);

        return dp[i][amount]=min(take,nottake);
    }
};