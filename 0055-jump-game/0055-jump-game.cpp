class Solution {
public:
    bool canJump(vector<int>& arr) {
        int current=0;
        int destination=arr.size()-1;
        for(int i=0;i<arr.size();i++){
            if(current >= i){
                current = max(current, i+arr[i]);
            }
            if(current>=destination){
                return true;
            }
        }
        return false;
    }
};