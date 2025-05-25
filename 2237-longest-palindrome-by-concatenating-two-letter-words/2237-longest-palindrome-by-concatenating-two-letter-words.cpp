class Solution {
public:
    string reverse(const string &str) {
        string rev = str;
        int start = 0, end = rev.size() - 1;
        while (start < end) {
            swap(rev[start++], rev[end--]);
        }
        return rev;
    }

    bool isPalindrome(const string &str) {
        int start = 0, end = str.size() - 1;
        while (start < end) {
            if (str[start++] != str[end--]) {
                return false;
            }
        }
        return true;
    }

    int longestPalindrome(vector<string>& arr) {
        unordered_map<string, int> freq;
        int res = 0;
        bool centerUsed = false;

        for (const string &s : arr) {
            freq[s]++;
        }

        for (auto &[s, count] : freq) {
            string rev = reverse(s);
            if (s == rev) {  // Palindromic string
                int pairs = count / 2;
                res += pairs * 4;
                freq[s] -= pairs * 2;
                if (!centerUsed && freq[s] > 0) {
                    res += 2;
                    centerUsed = true;
                }
            } else if (freq.find(rev) != freq.end()) {
                int pairs = min(freq[s], freq[rev]);
                res += pairs * 4;
                freq[s] -= pairs;
                freq[rev] -= pairs;
            }
        }

        return res;
    }
};
