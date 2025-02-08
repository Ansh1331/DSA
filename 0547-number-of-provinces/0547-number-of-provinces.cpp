class Solution {
private:
    void dfss(int node,vector<vector<int>> adj,vector<int>& vis){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfss(it,adj,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int V=adj.size();
        int count=0;
        vector<int> vis(V,0);

        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                count++;
                dfss(i,adj,vis);
            }
        }
        return count;
    }
};