class Solution {
public:
    bool rotateString(string s, string goal) {
        string ans = s+s;
        if(s.size()!=goal.size()) return false;
        int len = ans.size()-goal.size();
        for(int i=0;i<ans.size();i++)
        {
            if(ans.substr(i,len)==goal){
                return true;
            }
        }
        return false;
    }
};