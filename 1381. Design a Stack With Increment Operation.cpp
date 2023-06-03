class CustomStack {
public:
    int size = 0;
    vector<int> res;
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(res.size() < size)
            res.push_back(x);
    }
    
    int pop() {
        int top = -1;
        if(res.size()){
            top = res.back();
            res.pop_back();
        }
        return top;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<res.size() && i<k;i++)
            res[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
