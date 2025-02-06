class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string mpp[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        if(digits.size()==0) return ans;

        string temp;
        solve( 0 , digits , ans , temp , mpp );
        return ans;
    }

    void solve( int idx , string digits , vector<string>& ans , string& temp , string mpp[]){
        if(idx==digits.size()){
            ans.push_back(temp);
            return;
        }
        int x = digits[idx] - '0' ;
        string value = mpp[x];

        for(int i=0 ; i<value.size() ; i++)
        {
            temp.push_back(value[i]);
            solve(idx+1 , digits , ans , temp , mpp);
            temp.pop_back();
        }

    }

    
};