class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> temp(n);
        for(int i=0;i<n;i++)
        {
            temp[i] = s;
        }
        solve(temp , 0 , n , ans);
        return ans;
    }
    void solve(vector<string>& temp , int row , int n , vector<vector<string>>& ans)
    {
        if(row==n)
        {
            ans.push_back(temp);
        }
        
        for(int j=0;j<n;j++)
        {
            if(isSafe(temp , row , j , n))
            {
                temp[row][j] = 'Q';
                solve(temp,row+1,n,ans);
                temp[row][j] = '.';
            }
        }
    }
    bool isSafe(vector<string>& temp , int row , int col ,int n )
    {
        
        for(int i=0 ; i<n ; i++)
        {
            if(temp[i][col]=='Q') return false;
        }

        for(int i=row,j=col ; i>=0 && j>=0 ; i--,j--)
        {
            if(temp[i][j]=='Q') return false;
        }

        for(int i=row,j=col ; i>=0 && j<n ; i--,j++)
        {
            if(temp[i][j]=='Q') return false;
        }
        
        return true;
    }
};