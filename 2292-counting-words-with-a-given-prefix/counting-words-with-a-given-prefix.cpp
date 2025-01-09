class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int x=pref.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(words[i].substr(0,x)==pref) cnt++;
        }
        return cnt;
    }
};