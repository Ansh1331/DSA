class Solution {
private:
    bool dfs(vector<vector<int>>& graph,vector<int>& vis,vector<int>& pathvis,int node,vector<int>& check){
        vis[node]=1;
        pathvis[node]=1;

        for(auto it: graph[node]){
            if(!vis[it]){
                if(dfs(graph,vis,pathvis,it,check)) return true;
            }
            else if(vis[it] && pathvis[it]){
                return true;
            }
        }
        check[node]=1;
        pathvis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        vector<int> check(V,0);
        vector<int> safenodes;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(graph,vis,pathvis,i,check);
            }
        }

        for(int i=0;i<V;i++){
            if(check[i]==1){
                safenodes.push_back(i);
            }
        }

        return safenodes;

    }
};