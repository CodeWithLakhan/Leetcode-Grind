class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        vector<vector<int>> vis(r , vector<int>(c,0));
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                vis[i][0]=1;
            }
            if(board[i][c-1]=='O'){
                q.push({i,c-1});
                vis[i][c-1]=1;
            }
        }
        for(int i=0;i<c;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                vis[0][i]=1;
            }
            if(board[r-1][i]=='O'){
                q.push({r-1,i});
                vis[r-1][i]=1;
            }
        }
        
        int drow[4] = {0,1,0,-1};
        int dcol[4] = {-1,0,1,0};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 && nrow<r && ncol>=0 && ncol<c && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};