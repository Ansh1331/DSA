class Solution {
public:

    int leastInterval(vector<char>& arr, int n) {
        priority_queue<int> pq;
        unordered_map<char,int>mpp;
        for(auto it:arr){
            mpp[it]++;
        }
        for(auto it:mpp){
            pq.push(it.second);
        }

        int time=0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for (int i = 0; i < temp.size(); i++) {
    if (temp[i] > 0) {   // ✅ only push tasks that are still left
        pq.push(temp[i]);
    }
}


            if(pq.empty()){
                time+=temp.size();
            }
            else{
                time+=n+1;
            }
        }
        return time;
    }
};