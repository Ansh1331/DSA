class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        
        // If size of nums1 is odd, XOR all elements of nums2
        if (nums1.size() % 2 == 1) {
            for (int num : nums2) {
                res ^= num;
            }
        }
        
        // If size of nums2 is odd, XOR all elements of nums1
        if (nums2.size() % 2 == 1) {
            for (int num : nums1) {
                res ^= num;
            }
        }
        
        return res;
    }
};
