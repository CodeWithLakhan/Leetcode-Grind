class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int cnt[26]={0};
            for(int j=i;j<n;j++)
            {
                cnt[s[j]-'a']++;
                int leastFrequent = INT_MAX;
                int mostFrequent = INT_MIN;
                for(int k=0;k<26;k++)
                {
                    if(cnt[k]>0){
                    leastFrequent = min(leastFrequent,cnt[k]);
                    mostFrequent = max(mostFrequent,cnt[k]);}
                }
                ans = ans + (mostFrequent-leastFrequent);
            }
        }
        return ans;
    }
};