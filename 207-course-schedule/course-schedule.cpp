class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        for(int i=0;i<p.size();i++){
            adj[p[i][0]].push_back(p[i][1]);
        }

        vector<int> vis(n,0);
        vector<int> pathvis(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(topo(i ,  vis , adj , pathvis)) return false;
            }
        }
        return true;
    }

    bool topo(int node ,  vector<int>& vis , vector<vector<int>>& adj, vector<int>& pathvis){
        vis[node]=1;
        pathvis[node]=1;

        for(auto it: adj[node]){
            if(!vis[it]){
                if(topo(it,vis,adj,pathvis)) return true;
            }
            else if(pathvis[it]) return true;
        }   

        pathvis[node]=0;
        return false;

    }
};