class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edge, int disanceThreshold) {
        vector<vector<int>> dis(n,vector<int>(n,1e8));

        for(auto it:edge){
            dis[it[0]][it[1]]= it[2];
            dis[it[1]][it[0]]= it[2];
        }
        for(int i=0;i<n;i++) { //all self nodes 0
            dis[i][i]=0;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dis[i][k] != 1e8 && dis[k][j]!= 1e8){
                        dis[i][j] = min(dis[i][j], 
                                     dis[i][k] + dis[k][j]);
                        
                    }
                }
            }
        }

        int maxcity=n;
        int index=-1;

        for(int city=0;city<n;city++){
            int counter=0;
            for(int neighbour=0;neighbour<n;neighbour++){
                if(dis[city][neighbour] <= disanceThreshold){
                    counter++;
                }
            }
            if(counter<=maxcity){
                maxcity=counter;
                index=city;
            }
        }
        return index;

    }
};