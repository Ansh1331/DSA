class Solution {
public:
    int leastInterval(vector<char>& arr, int n) {
        // int n=arr.size();
        priority_queue<int> pq;
        vector<int> mpp(26,0);
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]-'A']++;
        }
        int res=0;

        for(int i=0;i<26;i++){
            if(mpp[i]>0){
                pq.push(mpp[i]);
            }
        }

        int time=0;
        while(!pq.empty()){
            vector<int>temp;
            for(int i=0;i<=n;i++){
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
                time+=temp.size();
            }
            else{
                time+=n+1;
            }
        }
        return time;
    }
};