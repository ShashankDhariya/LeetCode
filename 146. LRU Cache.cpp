class LRUCache {
public:

    class Node { 
        public:
            int key;
            int val;
            Node* next;
            Node* prev;
        Node(int a, int b){
            key = a;
            val = b;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int n;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        n = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* ptr){
        Node* temp = head->next;
        ptr->next = temp;
        ptr->prev = head;
        temp->prev = ptr;
        head->next = ptr;
        mp[ptr->key] = ptr;
    }

    void deleteNode(Node* ptr){
        Node* nNode = ptr->next;
        Node* pNode = ptr->prev;
        pNode->next = nNode;
        nNode->prev = pNode;
    }

    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* ptr = mp[key];
            int val = ptr->val;
            mp.erase(key);
            deleteNode(ptr);
            addNode(ptr);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            deleteNode(mp[key]);
            mp.erase(key);
        }

        if(mp.size() == n){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
