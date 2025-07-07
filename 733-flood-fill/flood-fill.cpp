class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& arr, int sr, int sc, int color) {
        int r = arr.size();
        int c = arr[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        if(arr[sr][sc]==color) return arr;
        int target = arr[sr][sc];
        arr[sr][sc]=color;

        int drow[4] = {0,1,0,-1};
        int dcol[4] = {-1,0,1,0};

        vector<vector<int>> vis(r,vector<int>(c,0));
        vis[sr][sc]=1;

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                if(nrow>=0 && nrow<r && ncol>=0 && ncol<c && arr[nrow][ncol]==target && !vis[nrow][ncol]){
                    q.push({nrow,ncol});
                    arr[nrow][ncol]=color;
                    vis[nrow][ncol]=1;
                }
            }
        }
        return arr;
    }
};