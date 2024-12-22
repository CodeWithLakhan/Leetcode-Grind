class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++)
        {
            ans.push_back(generateRow(i));
        }
        return ans;
    }

    vector<int> generateRow(int row){
        vector<int> ansrow;
        long long ans=1;
        ansrow.push_back(1);
        for(int i=1;i<row;i++)
        {
            ans = ans* (row-i);
            ans = ans/i;
            ansrow.push_back(ans);
        }
        return ansrow;
    }
};