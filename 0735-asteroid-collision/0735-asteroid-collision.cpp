class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n=arr.size();
        vector<int> lt;

        for(int i=0;i<n;i++){
            //+ve
            if(arr[i]>=0){
                lt.push_back(arr[i]);
            }

            //-ve
            else if(arr[i]<0){
                int negnum= abs(arr[i]);
                while(!lt.empty() && lt.back()>0 && negnum > lt.back()){
                    lt.pop_back();
                }
                if(!lt.empty() && lt.back()==negnum){
                        lt.pop_back();
                    }
                    else if(lt.empty() || lt.back()<0){
                        lt.push_back(arr[i]);
                    }

            }

        }
        return lt;
    }
};