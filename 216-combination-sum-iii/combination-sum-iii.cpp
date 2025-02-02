class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(1 , 0 , k , n , curr , ans);
        return ans;
    }
    void solve(int idx , int curSum , int k , int n , vector<int> &curr , vector<vector<int>> &ans){
        if(curr.size()==k)
        {
            if(curSum==n)
            {
                ans.push_back(curr);
            }
            return;
        }
        for(int i=idx ; i<=9 ; i++)
        {
            if(curSum+i > n) break;
            curr.push_back(i);
            solve(i+1 , curSum+i , k , n  , curr , ans);
            curr.pop_back();
        }
    }
};