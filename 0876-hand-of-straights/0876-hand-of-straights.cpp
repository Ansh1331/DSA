class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int n) {
        if((hand.size()%n) !=0){
            return false;
        }

        map<int,int> mpp;

        for(int i=0;i<hand.size();i++){
            mpp[hand[i]]++;
        }

        while(!mpp.empty()){
            int curr= mpp.begin()->first; //second is frequency

            for(int i=0;i<n;i++){
                if(mpp[curr + i]==0){
                    return false;
                }

                mpp[curr+i]--;
                if(mpp[curr+i]<1){
                    mpp.erase(curr+i);
                }
            }
        }

        return true;

    }
};