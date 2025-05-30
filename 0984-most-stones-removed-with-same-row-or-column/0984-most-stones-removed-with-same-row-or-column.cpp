#include<bits/stdc++.h>
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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int rows=0;
        int cols=0;
        for(auto it:stones){
            rows=max(rows,it[0]);
            cols=max(cols,it[1]);
        }

        DisjointSet ds(rows+cols+1);
        int components=0;
        unordered_map<int,int> mpp; //for storing unique nodes
        for(auto it:stones){
            int nodeRow=it[0];
            int nodeCol=it[1] + rows +1; //column transformation
            ds.unionByRank(nodeRow,nodeCol);
            mpp[nodeRow]=1;
            mpp[nodeCol]=1;
        }

        for(auto it:mpp){
            if(it.first == ds.findUParent(it.first)){
                components++;
            }
        }
        return n-components;
    }
};

