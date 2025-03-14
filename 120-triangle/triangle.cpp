class Solution {
public:
    int minimumTotal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int> (m,-1));
        return solve( 0,0, grid,dp);
    }
    int solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(row==grid.size()-1)
        {
            return grid[row][col];
        }

        if(dp[row][col]!=-1) return dp[row][col];

        int right = grid[row][col] + solve(row+1,col,grid,dp);
        int down = grid[row][col] + solve(row+1,col+1,grid,dp);

        return dp[row][col]=min(right,down);
    }
};