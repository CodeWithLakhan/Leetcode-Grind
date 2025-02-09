class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> parts;

        solve( s , parts , ans);
        return ans;
    }
    
    void solve (string s , vector<string> &parts , vector<vector<string>> &ans){
        if(s.size()==0)
        {
            ans.push_back(parts);
            return;
        }
        for(int i=0;i<s.size() ; i++)
        {
            string temp = s.substr( 0 , i+1);
            if(ispalin(temp))
            {
                parts.push_back(temp);
                solve( s.substr(i+1 , s.size()-1) , parts , ans );
                parts.pop_back();
            }
        }
    }
    bool ispalin(string s){
            string x = s;
            reverse(x.begin() , x.end());
            return x==s;
        }
};