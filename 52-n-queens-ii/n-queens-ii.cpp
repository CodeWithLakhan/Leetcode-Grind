class Solution {
public:
    int totalNQueens(int n) {
        vector<string> temp(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            temp[i] = s;
        }
        int ans = 0;
        solve(temp , 0 , ans , n);
        return ans;
    }
    void solve(vector<string> &temp , int row , int &ans , int n)
    {
        if(row==n)
        {
            ans++;
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(isSafe(temp , row , i , n))
            {
                temp[row][i]='Q';
                solve(temp , row+1 , ans , n);
                temp[row][i]='.';
            }
        }
    }
    bool isSafe(vector<string> &temp , int row , int col , int n)
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