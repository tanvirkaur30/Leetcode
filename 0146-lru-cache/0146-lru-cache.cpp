class LRUCache {
    class Node{
        public:
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int key,int value){
          this->key = key;
          this->value = value;
          prev = NULL;
          next = NULL;
        }
    };
    Node* head ;
    Node* tail ;
    int cap ;
    unordered_map<int,Node*>mp;
    void deletenode(Node* node){
       Node* back = node->prev;
       back->next = node->next;
       node->next->prev = back;
    }
    void insertafterhead(Node* node){
        node->next = head->next;
        head->next = node;
        node->next->prev=node;
        node->prev=head;
    }
public:
    LRUCache(int capacity) {
    cap = capacity;
    head = new Node(-1,-1);
    tail = new Node(-1,-1);
    head->next = tail;
    tail->prev = head;
    }
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* node = mp[key];
        deletenode(node);
        insertafterhead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            node->value =value;
            deletenode(node);
            insertafterhead(node);
        }
        else{
            if(mp.size()==cap){
                Node* back = tail->prev;
                mp.erase(back->key);
                deletenode(back);
                delete back; 
            }
            Node* node = new Node(key,value);
            mp[key]= node;
            insertafterhead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */





































