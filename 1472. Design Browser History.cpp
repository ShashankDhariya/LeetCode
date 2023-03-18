class BrowserHistory {
public:
    stack<string> st;
    stack<string> st1;
    BrowserHistory(string homepage) {
        st.push(homepage);
        st1 = stack<string>();
    }
    
    void visit(string url) {
        st.push(url);
        st1 = stack<string>();
    }
    
    string back(int steps) {
        while(st.size() > 1 && steps--){
            auto curr = st.top();
            st.pop();
            st1.push(curr);
        }
        return st.top();
    }
    
    string forward(int steps) {
        while(!st1.empty() && steps--){
            auto curr = st1.top();
            st1.pop();
            st.push(curr);
        }
        return st.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
