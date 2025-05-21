class Node{
    public:     
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key,int _val){
            key=_key;
            val=_val;
        }
};
class LRUCache {
public:
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int cap;
    unordered_map<int,Node*> mpp;

    LRUCache(int capacity) {
        head->next=tail;
        tail->prev=head;
        cap=capacity;
    }

    void addnode(Node* node){
         node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
    }

    void deletenode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
        //delete(node);
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()){
            Node* node= mpp[key];
            int val=node->val;
            deletenode(node);
            addnode(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* node= mpp[key];
            node->val=value;
            deletenode(node);
            addnode(node);
            return;
        }

        if(mpp.size()==cap){
            Node* lru=tail->prev;
            mpp.erase(lru->key);
            deletenode(lru);
            delete(lru);
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