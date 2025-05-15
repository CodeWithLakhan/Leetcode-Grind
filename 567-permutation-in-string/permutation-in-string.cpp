class Solution {
public:

    bool check(int freq1[] , int freq2[])
    {
        for(int i=0;i<26;i++)
        {
            if(freq1[i]!=freq2[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        int s1Size = s1.size();
        for(int i=0;i<s1Size ; i++)
        {
            freq[s1[i] - 'a']++;
        }
        for(int i=0;i<s2.size();i++)
        {
            int tempfreq[26]={0};
            int tempidx=0;
            int idx=i;
            while(tempidx < s1Size && idx < s2.size())
            {
                tempfreq[s2[idx]-'a']++;
                tempidx++;
                idx++;
            }
            if(check(freq,tempfreq)){
                return true;
            }
        }
        return false;
    }
};