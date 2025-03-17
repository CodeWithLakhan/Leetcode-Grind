class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum%2!=0) return false;
        sum = sum /2;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));        
        return findans(nums , sum ,  n-1,dp);
    }

    bool findans(vector<int>& nums , int sum , int idx ,vector<vector<int>>& dp)
    {
        if(sum==0) return true;
        if(idx==0) return (nums[0]==sum);
        if(dp[idx][sum]!=-1) return dp[idx][sum];

        bool nottake = findans(nums,sum,idx-1,dp);
        int take = false;
        if(sum>=nums[idx]) take = findans(nums,sum-nums[idx],idx-1,dp);

        return dp[idx][sum]= take || nottake;
    }

};