class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
         vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(n-1 , amount ,  coins , dp);
    }
    int solve(int i , int target ,vector<int>& coins , vector<vector<int>>& dp)
    {
        if(target==0)
        {
            return 1;
        }
        if(i==0)
        {
            if(target%coins[i]==0) return 1;
            return 0;
        }
          if (dp[i][target] != -1) return dp[i][target];

        int nottake = solve(i-1,target,coins,dp);
        int take = 0;
        if(coins[i]<=target) take = solve(i, target-coins[i],coins,dp);
        
        return dp[i][target]=take+nottake;
    }
};