class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        int k = truckSize;
        int ans = 0;
        sort(boxTypes.begin(), boxTypes.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] > b[1]; });
        for (int i = 0; i < n; i++) {
            if (boxTypes[i][0] <= k) {
                ans = ans + (boxTypes[i][0] * boxTypes[i][1]);
                k = k - boxTypes[i][0];
            } else if (boxTypes[i][0] > k) {
                ans = ans + (k * boxTypes[i][1]);
                break;
            }
            if (k == 0)
                break;
        }
        return ans;
    }
};