class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MIN));
        int i=0,j=0;

        return solve(i,j,nums1,nums2,dp);
        
    }
    int solve(int i, int j , vector<int>& nums1, vector<int>& nums2,vector<vector<int>>& dp ){
        if(i==nums1.size() || j==nums2.size()){ return -1e9;}
        if(dp[i][j]!=INT_MIN) return dp[i][j];

        int take = nums1[i] * nums2[j] + max(0,solve(i+1,j+1,nums1,nums2,dp));

        int skip1 = solve(i+1,j,nums1,nums2,dp);

        int skip2 = solve(i,j+1,nums1,nums2,dp);

        return dp[i][j]=max(take,max(skip1,skip2));

    }
};