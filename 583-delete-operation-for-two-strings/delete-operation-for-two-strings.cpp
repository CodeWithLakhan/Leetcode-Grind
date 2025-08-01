class Solution {
public:
    int minDistance(string text1, string text2) {
        int n= text1.size();
        int m= text2.size();
        
        vector<vector<int>> dp(n,vector<int> (m,-1));
        int x = solve(n-1 , m-1 , dp , text1 , text2);
        return n-x+m-x;
    }
    int solve(int i, int j, vector<vector<int>>& dp , string& t1 , string& t2){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(t1[i]==t2[j]){
            return dp[i][j]=1 + solve(i-1,j-1,dp,t1,t2);
        }

        return dp[i][j] = max(solve(i-1,j,dp,t1,t2),solve(i,j-1,dp,t1,t2));
    }
};