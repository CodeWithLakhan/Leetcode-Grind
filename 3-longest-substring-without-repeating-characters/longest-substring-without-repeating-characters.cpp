class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if (n==0) return 0;
        int r=0,l=0;
        unordered_map<char, int> mpp;
        int ans = INT_MIN;
        int len;
        
        while(r<n)
        {
            if(mpp.find(s[r])!=mpp.end())
            {
                if(mpp[s[r]]>=l)
                {
                    l = mpp[s[r]]+1;
                }
            }
            
                len = r-l+1;
                ans = max(ans,len);
                mpp[s[r]]=r;
                r++;
            
        }
        return ans;
    }
};