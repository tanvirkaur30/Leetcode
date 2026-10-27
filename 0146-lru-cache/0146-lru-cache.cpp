class LRUCache {
    class Node {
    public:
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };
public:
    unordered_map<int, Node*> mp;
    int capacity ;
    Node* head ;
    Node* tail;
    LRUCache(int capacity) {
        this->capacity = capacity ;
       head = new Node(-1, -1);
       tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void deletenode(Node* node){//change the links only not actually delete it 
        Node* Prev = node->prev;
        Prev->next = node->next;
        node->next->prev = Prev;
      
    }
    void insertafterhead(Node* node){
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
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
            node->value = value;
            deletenode(node);
            insertafterhead(node);
        }
        else{
            if(capacity==mp.size()){
                Node* node =tail->prev;
                mp.erase(node->key);
                deletenode(node);
                delete node;
            }
            Node* node = new Node(key,value);
            mp[key]=node;
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