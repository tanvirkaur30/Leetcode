
class LFUCache {
    // Represents one key-value pair in the cache
    struct Node {
        int key, value, cnt;
        Node* next;
        Node* prev;

        Node(int _key, int _value) {
            key = _key;
            value = _value;
            cnt = 1;
            next = nullptr;
            prev = nullptr;
        }
    };

    // Doubly linked list for nodes having the same frequency
    struct List {
        int size;
        Node* head;
        Node* tail;

        List() {
            head = new Node(0, 0);
            tail = new Node(0, 0);

            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        // Insert node at the front: most recently used
        void addFront(Node* node) {
            Node* temp = head->next;

            node->next = temp;
            node->prev = head;

            head->next = node;
            temp->prev = node;

            size++;
        }

        // Unlink a node without deleting its memory
        void removeNode(Node* node) {
            Node* before = node->prev;
            Node* after = node->next;

            before->next = after;
            after->prev = before;

            size--;
        }

        // Least recently used node in this frequency list
        Node* removeLast() {
            if (size == 0) return nullptr;

            Node* node = tail->prev;
            removeNode(node);
            return node;
        }
    };

    int capacity;
    int curSize;
    int minFreq;

    // Key -> corresponding node
    unordered_map<int, Node*> keyNode;

    // Frequency -> corresponding doubly linked list
    unordered_map<int, List*> freqListMap;

    // Move an accessed node to the next frequency list
    void updateFreqListMap(Node* node) {
        int oldFreq = node->cnt;

        // Remove node from its old frequency list
        freqListMap[oldFreq]->removeNode(node);

        // If the old minimum-frequency list is empty
        if (oldFreq == minFreq &&
            freqListMap[oldFreq]->size == 0) {
            minFreq++;
        }

        // Increase the node's frequency
        node->cnt++;

        // Create a list for this frequency if needed
        if (freqListMap.find(node->cnt) == freqListMap.end()) {
            freqListMap[node->cnt] = new List();
        }

        // Insert at front of the new frequency list
        freqListMap[node->cnt]->addFront(node);
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        curSize = 0;
        minFreq = 0;
    }

    int get(int key) {
        // Key does not exist
        if (keyNode.find(key) == keyNode.end()) {
            return -1;
        }

        Node* node = keyNode[key];
        int val = node->value;

        // Accessing a key increases its frequency
        updateFreqListMap(node);

        return val;
    }

    void put(int key, int value) {
        // A zero-capacity cache cannot store anything
        if (capacity == 0) return;

        // Case 1: key already exists
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];

            node->value = value;
            updateFreqListMap(node);
            return;
        }

        // Case 2: new key and cache is full
        if (curSize == capacity) {
            List* list = freqListMap[minFreq];

            // Remove the least recently used node
            Node* node = list->removeLast();

            keyNode.erase(node->key);
            delete node;

            curSize--;
        }

        // New keys always start at frequency 1
        Node* node = new Node(key, value);

        if (freqListMap.find(1) == freqListMap.end()) {
            freqListMap[1] = new List();
        }

        freqListMap[1]->addFront(node);
        keyNode[key] = node;

        curSize++;
        minFreq = 1;
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */