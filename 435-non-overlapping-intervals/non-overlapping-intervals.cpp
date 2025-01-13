class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int cnt = 0;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        int lastend = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if(intervals[i][0]>=lastend){
                lastend=intervals[i][1];
            }else{
                cnt++;
            }
        }
        return cnt;
    }
};