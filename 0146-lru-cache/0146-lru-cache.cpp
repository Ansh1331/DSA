class LRUCache {
public:
    public:
        class node {
            public:
                int key;
                int val;
                node * next;
                node * prev;
                node(int _key, int _val) {
                    key = _key;
                    val = _val;
                }
        };

    node * head = new node(-1, -1);
    node * tail = new node(-1, -1);

    int cap;
    unordered_map <int,node * > m;


    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addnode(node* newnode){
        newnode->next=head->next;
        newnode->prev=head;
        head->next=newnode;
        newnode->next->prev=newnode;
    }

    void deletenode(node* newnode){
        newnode->next->prev=newnode->prev;
        newnode->prev->next=newnode->next;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            node* resnode=m[key];
            int res=resnode->val;
            deletenode(resnode);
            addnode(resnode);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            node* modifynode = m[key];
            modifynode->val = value;
            deletenode(modifynode); // Correct order
            addnode(modifynode);    // Correct order
            return;                // No need to reassign m[key]
        }

        if (m.size() == cap) {
            m.erase(tail->prev->key);  // Remove LRU from the map
            deletenode(tail->prev);    // Remove LRU from the list
        }

        node* newnode = new node(key, value); // Create new node
        addnode(newnode);                     // Add it to the front
        m[key] = newnode;                     // Update map with new node
}

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */