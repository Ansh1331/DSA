class DisjointSet{
public:
    vector<int> parent,rank;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUParent(int node){
        if(parent[node]==node) return node;
        return parent[node]= findUParent(parent[node]);
    }
    
    void unionByRank(int u,int v){
        int ultimateParent_u= findUParent(u);
        int ultimateParent_v= findUParent(v);
        if(ultimateParent_u == ultimateParent_v) return;
        if(rank[ultimateParent_u] < rank[ultimateParent_v]) {
            parent[ultimateParent_u]= ultimateParent_v;
        }
        else if(rank[ultimateParent_u] > rank[ultimateParent_v]){
            parent[ultimateParent_v]= ultimateParent_u;
        }
        else{
            parent[ultimateParent_v]= ultimateParent_u;
            rank[ultimateParent_u]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findUParent(u) == ds.findUParent(v)){
                extra++;
            }
            else{
                ds.unionByRank(u,v);
            }
        }

        int components=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                components++;
            }
        }
        int required=components-1;
        if(extra >= required){
            return required;
        }
        
        return -1;
    }
}; 