class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> balCol;
        unordered_map<int,int> colBal;
        vector<int> ans;

        int n=queries.size();
        for(int i=0;i<n;i++)
        {
            int bal = queries[i][0];
            int col = queries[i][1];
            int x = balCol[bal];
            if(colBal.find(x) != colBal.end())
            {
                colBal[x]--;
                if (colBal[x]==0) colBal.erase(x);
            }
            colBal[col]++;
            balCol[bal] = col;
            ans.push_back(colBal.size());
        }
        return ans;


    }
};