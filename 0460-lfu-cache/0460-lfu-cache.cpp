class LFUCache {
    struct Node {
        int key, value, freq;
        Node *prev, *next;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
            prev = next = nullptr;
        }
    };

    struct DLL {
        Node *head, *tail;
        int size;

        DLL() {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void addFront(Node* node) {
            node->next = head->next;
            node->prev = head;

            head->next->prev = node;
            head->next = node;

            size++;
        }

        void remove(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }

        Node* removeLast() {
            if (size == 0) return nullptr;

            Node* node = tail->prev;
            remove(node);
            return node;
        }
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node*> keyNode;
    unordered_map<int, DLL*> freqList;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void updateFreq(Node* node) {
        int freq = node->freq;

        freqList[freq]->remove(node);

        if (freq == minFreq && freqList[freq]->size == 0)
            minFreq++;

        node->freq++;

        if (!freqList.count(node->freq))
            freqList[node->freq] = new DLL();

        freqList[node->freq]->addFront(node);
    }

    int get(int key) {
        if (!keyNode.count(key))
            return -1;

        Node* node = keyNode[key];
        updateFreq(node);

        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyNode.count(key)) {
            Node* node = keyNode[key];
            node->value = value;
            updateFreq(node);
            return;
        }

        if (keyNode.size() == capacity) {
            Node* node = freqList[minFreq]->removeLast();
            keyNode.erase(node->key);
            delete node;
        }

        Node* node = new Node(key, value);

        minFreq = 1;

        if (!freqList.count(1))
            freqList[1] = new DLL();

        freqList[1]->addFront(node);

        keyNode[key] = node;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */