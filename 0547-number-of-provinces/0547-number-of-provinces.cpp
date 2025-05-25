class Solution {
public:
    void dfs(int node,vector<vector<int>> adj,vector<int>& vis ){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& arr) {
        int n=arr.size();
        int count=0;
      //  vector<int> res;
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;
    }
};