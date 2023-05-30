class MyHashSet {
public:
    vector<int> set;
    MyHashSet() {
        
    }
    
    void add(int key) {
        bool b = contains(key);
        if(b)
            return;
        set.push_back(key);
    }
    
    void remove(int key) {
        bool b = contains(key);
        if(!b)
            return;

        int n = set.size();
        for(int i=0;i<n;i++){
            if(set[i] == key){
                swap(set[i], set[n-1]);
                set.pop_back();
                return;
            }
        }
    }
    
    bool contains(int key) {
        int n = set.size();
        for(int i=0;i<n;i++){
            if(set[i] == key)
                return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
