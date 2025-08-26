class Solution {
public:
    void helper(vector<vector<int>>&res,vector<int>temp,int index,int sum,int target,int k){
        if(temp.size()==k && sum==target){
            res.push_back(temp);
            return;
        }

        if(temp.size()> k || sum>target){
            return;
        }

        for(int i=index;i<10;i++){
            temp.push_back(i);
            helper(res,temp,i+1,sum+i,target,k);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        //sort(arr.begin(),arr.end());
        vector<int> temp;
        //int n=arr.size();
        int sum=0;
        helper(res,temp,1,sum,n,k);
        return res;
    }
};