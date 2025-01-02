class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        int l=0,h=m-1;
        while(l<=h)
        {
            int mid = (l+h)/2;
            int row = check(mat,n,m,mid);
            int left = (mid-1>=0)? mat[row][mid-1] : -1;
            int right = (mid+1<m)? mat[row][mid+1] : -1;
            if(mat[row][mid]>left && mat[row][mid]>right) return {row,mid};
            else if(mat[row][mid]<left) h=mid-1;
            else l=mid+1;
        }
        return {-1,-1};
    }
    int check (vector<vector<int>>& mat , int n , int m , int mid)
    {
        int x,temp = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(mat[i][mid]>temp)
            {
                temp = mat[i][mid];
                x = i;
            }
        }
        return x;
    }
};