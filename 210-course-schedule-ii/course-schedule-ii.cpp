class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        for(int i=0;i<p.size();i++){
            adj[p[i][1]].push_back(p[i][0]);
        }

        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        stack<int> st;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(topo(i ,  st , vis , adj , pathvis)) return {};
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
    bool topo(int node , stack<int>& st , vector<int>& vis , vector<vector<int>>& adj, vector<int>& pathvis){
        vis[node]=1;
        pathvis[node]=1;

        for(auto it: adj[node]){
            if(!vis[it]){
                if(topo(it,st,vis,adj,pathvis)) return true;
            }
            else if(pathvis[it]) return true;
        }   

        st.push(node);
        pathvis[node]=0;
        return false;

    }
};