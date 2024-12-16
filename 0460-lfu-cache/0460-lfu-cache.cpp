struct Node{
    int key,value,count;
    Node* next;
    Node* prev;
    Node(int key_,int value_){
        key=key_;
        value=value_;
        count=1;
    }
};

struct List{
    Node* head;
    Node* tail;
    int size;

    List(){
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        size=0;
    }

    void addnode(Node* newnode){
        Node* temp= head->next;
        newnode->next=temp;
        newnode->prev=head;
        temp->prev=newnode;
        head->next=newnode;
        size++;
    }

    void deletenode(Node* newnode){
        Node* delprev=newnode->prev;
        Node* delnext=newnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
        size--;
    }
};

class LFUCache {
private:
    map<int,Node*> keynode;
    map<int,List*> freqListmap;
    int maxsizecache;
    int minfreq;
    int currsize;

public:
    LFUCache(int capacity) {
        maxsizecache=capacity;
        minfreq=0;
        currsize=0;
    }

    void updatefreqListmap(Node* node){
        keynode.erase(node->key);
        freqListmap[node->count]->deletenode(node);

        if(node->count==minfreq && freqListmap[node->count]->size==0){
            minfreq++;
        }

        List *higherfreqList=new List();
        if(freqListmap.find(node->count+1) != freqListmap.end()){
            higherfreqList= freqListmap[node->count+1];
        }
        node->count+=1;
        higherfreqList->addnode(node);
        freqListmap[node->count]=higherfreqList;
        keynode[node->key]=node;
    }
    
    int get(int key) {
        if(keynode.find(key) != keynode.end()){
            Node* resnode=keynode[key];
            int res=resnode->value;
            updatefreqListmap(resnode);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxsizecache==0){
            return;
        }

        if(keynode.find(key) != keynode.end()){
            Node * resnode=keynode[key];
            resnode->value=value;
            updatefreqListmap(resnode);
        }
        else{
            if(currsize==maxsizecache){
                List* modifyList=freqListmap[minfreq];
                keynode.erase(modifyList->tail->prev->key);
                freqListmap[minfreq]->deletenode(modifyList->tail->prev);
                currsize--;
            }
            currsize++;
            minfreq=1;

            List* newList= new List();
            if(freqListmap.find(minfreq) != freqListmap.end()){
                newList=freqListmap[minfreq];
            }
            Node* node=new Node(key,value);
            newList->addnode(node);
            keynode[key]=node;
            freqListmap[minfreq]=newList;

        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */