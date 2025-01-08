class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(i!=j && isPrefixAndSuffix(words[i],words[j]))
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    bool isPrefixAndSuffix(string s1 , string s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1>n2) return false;
        int i=0;
        for (int i = 0; i < n1; i++) {
            if (s1[i] != s2[i]) return false;
        }
        
        // Check if s1 is a suffix of s2
        for (int i = 0; i < n1; i++) {
            if (s1[n1 - i - 1] != s2[n2 - i - 1]) return false;
        }
        return true;
    }
};