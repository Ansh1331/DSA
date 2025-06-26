class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int count = 0;
        long long value = 0;
        int power = 0;

        // Start from the right (least significant bit)
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                count++;  // 0 doesn't increase value
            } else {
                if (power < 31) {  // Prevent overflow
                    long long bit = 1LL << power;
                    if (value + bit <= k) {
                        value += bit;
                        count++;
                    }
                }
            }
            power++;
        }

        return count;
    }
};
