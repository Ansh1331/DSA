class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        vector<long long> lengths;
        long long len = 1;
        for(int op : operations){
            len *= 2;
            lengths.push_back(len);
            if(len >= k) break;
        }

        char ch = 'a';
        for(int i = lengths.size() - 1; i >= 0; i--){
            long long half = lengths[i] / 2;
            if(k > half){
                k -= half;
                if(operations[i] == 1){
                    ch = (ch == 'z') ? 'a' : ch + 1;
                }
            }
        }

        return ch;
    }
};
