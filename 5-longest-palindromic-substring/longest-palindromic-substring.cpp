class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int start=0;
        int mx = INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if( j-i+1>mx && solve(dp,i,j,s))
                {
                    start=i;
                    mx = max(mx , j-i+1);
                }
            }
        }
        return s.substr(start,mx);
    }
    bool solve(vector<vector<int>>& dp , int i , int j , string& s)
    {
        if(j<=i) return true;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]) return  dp[i][j] = solve(dp,i+1,j-1,s);

        return dp[i][j]=false;
    }
};