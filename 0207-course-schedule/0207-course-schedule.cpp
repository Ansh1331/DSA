class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        //int n=pre.size();
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto it:pre){
            int u= it[0];
            int v= it[1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        if(topo.size()==numCourses) return true;

        return false;


    }
};