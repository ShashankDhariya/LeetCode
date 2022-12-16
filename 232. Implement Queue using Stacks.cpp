class MyQueue {
public:

    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int num = st2.top();
        st2.pop();

        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return num;
    }
    
    int peek() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int num = st2.top();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return num;
    }
    
    bool empty() {
        return st1.size()? false:true;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
