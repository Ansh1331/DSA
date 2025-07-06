class FindSumPairs {
public:
    vector<int> arr1;
    vector<int> arr2;
    unordered_map<int,int> freq2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1=nums1;
        arr2=nums2;
        for(int num :arr2){
            freq2[num] ++;
        }
    }
    
    void add(int index, int val) {
        int oldval= arr2[index];
        freq2[oldval]--;
        arr2[index]+=val;
        freq2[arr2[index]]++;
    }
    
    int count(int tot) {
        int count=0;

        for(int num:arr1){
            int rem= tot- num;
            if(freq2.count(rem)){
                count += freq2[rem];
            }
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */