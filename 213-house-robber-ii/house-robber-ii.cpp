class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> t1 , t2;
        for(int i=0;i<n;i++)
        {
            if(i!=0) t1.push_back(nums[i]);
            if(i!=n-1) t2.push_back(nums[i]);
        }
        return max(solve(t1),solve(t2));
    }
    int solve(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(dp[0],nums[1]);

        for(int i=2;i<n;i++)
        {
            dp[i] = max( dp[i-1] , nums[i]+dp[i-2]);
            // cout<<"hehe"<<" "<<dp[i]<<endl;
        }
        return dp[n-1];
    }
};