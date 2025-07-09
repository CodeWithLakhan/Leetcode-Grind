class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int>> vis(r,vector<int>(c,0));
        vector<vector<int>> dis(r,vector<int>(c,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

        int drow[4] = {0,-1,0,1};
        int dcol[4] = {1,0,-1,0};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            dis[row][col]=dist;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 && nrow<r && ncol>=0 && ncol<c && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},dist+1});
                }
            }
        }
        return dis;
    }
};