class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int tsum = 0;
        for (int i = 0; i < n; i++)
            tsum += nums[i];
        if (tsum - target < 0 || (tsum - target) % 2 != 0)
            return 0;
        int reqSum = (tsum - target) / 2;
        vector<vector<int>> dp(n, vector<int>(reqSum + 1, -1));

        return solve(n - 1, (tsum - target) / 2, nums, dp);
    }
    int solve(int i, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        if (i == 0) {
            if (arr[i] == 0 && sum == 0)
                return 2;
            if (sum == 0 || sum == arr[i])
                return 1;
            return 0;
        }
        if (dp[i][sum] != -1)
            return dp[i][sum];

        int nottake = solve(i - 1, sum, arr, dp);
        int take = 0;
        if (arr[i] <= sum) {
            take = solve(i - 1, sum - arr[i], arr, dp);
        }
        return dp[i][sum] = take + nottake;
    }
};