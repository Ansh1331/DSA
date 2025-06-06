class Node{
    Node* links[2];
public:
    bool containsKey(int a){
        return links[a]!=NULL;
    }

    void put(int a,Node* node){
        links[a]= node;
    }

    Node* get(int a){
        return links[a];
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit= (num >> i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node= node->get(bit);
        }

    }

    int getMax(int num){
        Node* node=root;
        int res=0;
        for(int i=31;i>=0;i--){
            int bit= (num >> i) & 1;
            if(node->containsKey(1-bit)){
                res= res| (1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return res;
    }
};



class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxi = 0;
        Trie trie;
        
        trie.insert(nums[0]);
        
        for (int i = 1; i < nums.size(); ++i) {
            // For each number, find max XOR with previous ones
            maxi = max(maxi, trie.getMax(nums[i]));
            trie.insert(nums[i]); // then insert current number
        }
        return maxi;
    }
};