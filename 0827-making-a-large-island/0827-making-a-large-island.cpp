class DisjointSet{
public:
    vector<int> parent,rank,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
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

    void unionBySize(int u,int v){
        int pu= findUParent(u);
        int pv= findUParent(v);
        if(pu==pv) return;
        if(size[pu] <= size[pv]){
            parent[pu]=pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu] += size[pv];
        }
    }
};


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        int res=INT_MIN;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;

                int delrow[]={1,0,-1,0};
                int delcol[]={0,1,0,-1};
                for(int k=0;k<4;k++){
                    int nrow= i+ delrow[k];
                    int ncol= j+ delcol[k];
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==1){
                        int nodeno= i*n +j;
                        int adjnodeno= nrow* n + ncol;
                        ds.unionBySize(nodeno, adjnodeno);
                    }
                }
            }
        }

        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;

                int delrow[]={1,0,-1,0};
                int delcol[]={0,1,0,-1};
                set<int> st;
                for(int k=0;k<4;k++){
                    int nrow= row+ delrow[k];
                    int ncol= col+ delcol[k];
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==1){
                        int adjnodeno= nrow* n + ncol;
                        st.insert(ds.findUParent(adjnodeno));
                    }
                }
                int sizeTot=0;
                for(auto it:st){
                    sizeTot+= ds.size[it];
                }
                res=max(res,sizeTot+1);
            }
        }
        for(int i = 0; i < n*n; i++) {
            if(ds.findUParent(i) == i) {
                res = max(res, ds.size[i]);
            }
        }

        return res;
    }
};