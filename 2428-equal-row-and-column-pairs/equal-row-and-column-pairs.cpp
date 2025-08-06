class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mpp;
        for (int i = 0; i < grid.size(); i++) {
            mpp[grid[i]]++;
        }

        int ans = 0;
        int n = grid[0].size();

        for (int i = 0; i < n; i++) {
            vector<int> col;
            for (int j = 0; j < n; j++) {
                col.push_back(grid[j][i]);
            }
            if (mpp.count(col)) {
                ans += mpp[col];
            }
        }

        return ans;
    }
};
