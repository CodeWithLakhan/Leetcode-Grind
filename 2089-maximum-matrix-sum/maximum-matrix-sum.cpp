class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int nn=0, sn=INT_MAX;
        long long s=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]<=0) {nn++;
                }
                sn = min(sn,abs(matrix[i][j]));
                s = s + abs(matrix[i][j]);
            }
        }
        return nn%2==0? s : s - (2*sn);
    }
};