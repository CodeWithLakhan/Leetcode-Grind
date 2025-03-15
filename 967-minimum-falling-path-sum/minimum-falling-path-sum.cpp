class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=INT_MAX;
        vector<vector<int>> dp(n,vector<int> (n,-1));
        for(int i=0;i<n;i++)
        {
            dp[0][i] = grid[0][i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int l=1e9,r=1e9;
                if(j>0) l = grid[i][j] + dp[i-1][j-1];
                int up = grid[i][j] + dp[i-1][j];
                if(j<n-1)  r = grid[i][j] + dp[i-1][j+1];

                dp[i][j] = min(l,min(up,r));
            }
        }
        for(int i =0 ; i<n ; i++)
        {
            ans = min(ans,dp[n-1][i]);
        }
        return ans;

    }
    // int solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp)
    // {
    //     if(col<0 || col>=grid.size()) return 1e9;
    //     if(row==0)
    //     {
    //         return grid[row][col];
    //     }
    //     if(dp[row][col]!=-1) return dp[row][col];
    //     int l = grid[row][col] + solve(row-1,col-1,grid,dp);
    //     int up = grid[row][col] + solve(row-1,col,grid,dp);
    //     int r = grid[row][col] + solve(row-1,col+1,grid,dp);

    //     return dp[row][col]=min(l,min(up,r));
    // }
};