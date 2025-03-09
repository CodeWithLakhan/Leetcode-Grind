class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return solve(0, 0, days, costs, dp);
    }

    int solve(int i, int validDate, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if (i == days.size()) return 0; 
        
        if (validDate >= days[i]) return solve(i + 1, validDate, days, costs, dp); 
        
        if (dp[i] != -1) return dp[i]; 
        
        int mini = INT_MAX;

        mini = min(mini, costs[0] + solve(i + 1, days[i], days, costs, dp));

        mini = min(mini, costs[1] + solve(i + 1, days[i] + 6, days, costs, dp));

        mini = min(mini, costs[2] + solve(i + 1, days[i] + 29, days, costs, dp));

        return dp[i] = mini;
    }
};
