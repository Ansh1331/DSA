class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<int> dis(n,1e9);
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        //stop , (node,dis);
        pq.push({0,{src,0}});

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int stops=it.first;
            int node=it.second.first;
            int weight=it.second.second;
            
            if(stops>k) continue;

            for(auto q: adj[node]){
                int neigh= q.first;
                int neighWeight= q.second;

                if(weight+neighWeight < dis[neigh] && stops<=k){
                    dis[neigh]= weight+neighWeight;
                    pq.push({stops+1, {neigh, weight+neighWeight}});
                }
            }
        }
        if(dis[dst]==1e9) return -1;
        return dis[dst];
    }
};