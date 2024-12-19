class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mpp(26,0);
        priority_queue<int> pq; //max-heap by default
        int time=0;
        
        for(int i=0;i<tasks.size();i++){
            mpp[tasks[i]-'A']++;
        }


        for(int i=0;i<26;i++){
            if(mpp[i]>0){
                pq.push(mpp[i]);
            }
        }


        while(!pq.empty()){
            vector<int>temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int i=0;i<temp.size();i++){
                if(temp[i]>0){
                    pq.push(temp[i]);
                }
            }

            if(pq.empty()){
                time+= temp.size();
            }
            else{
                time+=n+1;
            }
        }
        return time;
    }
};