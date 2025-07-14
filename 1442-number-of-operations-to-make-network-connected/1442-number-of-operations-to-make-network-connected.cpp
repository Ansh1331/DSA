class DisjointSet{
public:
    vector<int> parent, rank;

    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findUParent(parent[node]);
    }

    void unionByRank(int u,int v){
        int pu= findUParent(u);
        int pv= findUParent(v);
        if(pu==pv) return;
        if(rank[pu] < rank[pv]){
            parent[pu]= pv;
        }
        else if(rank[pu] > rank[pv]){
            parent[pv]= pu;
        }
        else{
            parent[pu]=pv;
            rank[pv]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra=0;

        for(auto it: connections){
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

        int req= components-1;
        if(extra>=req){
            return req;
        }        
        return -1;
    }
};