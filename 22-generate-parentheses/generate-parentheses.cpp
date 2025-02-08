class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve( 0 , 0 , n , "" , ans );
        return ans;
    }
    void solve( int openNo , int closedNo ,  int n , string temp , vector<string>& ans ){
        if(openNo == closedNo && temp.size() == 2*n)
        {
            ans.push_back(temp);
            return;
        }
        if(openNo<n)
        {
            solve(openNo + 1 , closedNo , n , temp+"(" , ans);
        }
        if(closedNo<openNo)
        {
            solve(openNo , closedNo+1 , n , temp+")" , ans);
        }
    }
};