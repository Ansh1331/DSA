class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1); 
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dis(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> q;
        dis[k]=0;
        q.push({0,k});
        int res=0;

        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int time= it.first;
            int node=it.second;

            for(auto it:adj[node]){
                int neighbour= it.first;
                int neighbourtime=it.second;
                if(neighbourtime + time < dis[neighbour]){
                    dis[neighbour]= neighbourtime+time;
                    q.push({dis[neighbour],neighbour});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dis[i]== 1e9) return -1;
            res = max(res,dis[i]);
        }
        return res;

    }
};