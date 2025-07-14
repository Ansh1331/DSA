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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
       int n=accounts.size();
       DisjointSet ds(n);

       unordered_map<string,int> mpp;
       for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mpp.find(mail) == mpp.end()){
                    mpp[mail]=i;
                }
                else{
                    ds.unionByRank(i,mpp[mail]);
                }
            }
        }
        
        vector<vector<string>> ans;
        vector<vector<string>> temp(n);

        for(auto it:mpp){
            string mail= it.first;
            int node= ds.findUParent(it.second);
            temp[node].push_back(mail);
        }

        for(int i=0;i<n;i++){
            if(temp[i].size() == 0) continue;
            vector<string> res;
            res.push_back(accounts[i][0]);
            sort(temp[i].begin(),temp[i].end());
            for(auto it:temp[i]){
                res.push_back(it);
            }
            ans.push_back(res);
        }
        return ans;
    }
};
