class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if (n2 > n1)
            return "";
        unordered_map<char, int> mpp;
        int r = 0, l = 0;
        int minans = INT_MAX;
        for (int i = 0; i < n2; i++) {
            mpp[t[i]]++;
        }
        int cnt = 0;
        int sindex = -1;
        while (r < n1) {
            if (mpp[s[r]] > 0)
                cnt++;
            mpp[s[r]]--;

            while (cnt == n2) {
                if (r - l + 1 < minans) {
                    minans = r - l + 1;
                    sindex = l;
                }
                mpp[s[l]]++;
                if (mpp[s[l]] > 0)
                    cnt--;
                l = l + 1;
            }

            r = r + 1;
        }
        return sindex == -1 ? "" : s.substr(sindex, minans);
    }
};