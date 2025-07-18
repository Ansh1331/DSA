class Solution {
public:
    int timer=1;
    void dfs(int node, int parent,vector<int>& vis,int tin[],int low[],vector<vector<int>>& adj,vector<vector<int>> & bridges){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;

        for(auto it:adj[node]){
            if(it==parent) continue;    
            if(vis[it]==0){
                dfs(it,node,vis,tin,low,adj,bridges);
                low[node]= min(low[node],low[it]);
                if(low[it] > tin[node]){
                    bridges.push_back({it,node});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> bridges;
        vector<int> vis(n,0);
        int tin[n];
        int low[n];
        dfs(0,-1,vis,tin,low,adj,bridges);
        return bridges;
    }
};