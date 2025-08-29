class LRUCache {
public:
    class Node{
        public:
        int key;
        Node* next;
        Node* prev;
        int val;

        Node(int key_,int val_){
            key=key_;
            val=val_;
        }
    };

    int cap;
    unordered_map<int,Node*> mpp;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    void deletenode(Node* node){
        node->next->prev=node->prev;
        node->prev->next=node->next;
    }

    void addnode(Node* node){
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
    }

    LRUCache(int capacity) {
        cap=capacity;
         head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()){
            Node* node=mpp[key];
            deletenode(node);
            addnode(node);
            return node->val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* node=mpp[key];
            deletenode(node);
            node->val=value;
            addnode(node);
            return;
        }
        
        if(mpp.size()==cap){
            mpp.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        Node* newnode=new Node(key,value);
        addnode(newnode);
        mpp[key]=newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */