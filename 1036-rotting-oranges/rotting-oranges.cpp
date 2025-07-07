class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                else{
                    vis[i][j]=0;
                }
            }
        }

        int ans=0;
        int drow[4] = {0,1,0,-1};
        int dcol[4] = {1,0,-1,0};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            ans = max(ans,t);
            q.pop();
            for(int i=0;i<4;i++){
                int row = r + drow[i];
                int col = c + dcol[i];
                if(row>=0 && row<m && col>=0 && col<n && vis[row][col]!=2 && grid[row][col]==1){
                    vis[row][col]=2;
                    q.push({{row,col},t+1});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]!=2 && grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
};