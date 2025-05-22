class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int sz=queries.size();
        int j=0;
        int sum=0;
        sort(queries.begin(),queries.end());
        int count=0;
        priority_queue<int> pq;
        vector<int> diff(n+1,0);

        for(int i=0;i<n;i++){
            while(j<sz && queries[j][0]<=i){
                pq.push(queries[j][1]);
                j++;
            }

            while(sum+diff[i] < nums[i]){
                if(pq.empty()){
                return -1;}
                    

                int a=pq.top();
                pq.pop();
                if(a>=i){
                    diff[i]++;
                    diff[a+1]--;
                    count++;
                }
            }
            sum+=diff[i];
        }
        return sz-count;
    }
};