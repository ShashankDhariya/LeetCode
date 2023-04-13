class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int push = pushed.size();
        int pop = popped.size();

        int i = 0;
        int j = 0;

        stack<int> st;
        while(i < push || j < pop){
            if(st.empty()){
                if(i < push)
                    st.push(pushed[i++]);
                else 
                    return false;
            }
            else {
                if(j < pop && st.top() == popped[j]){
                    st.pop();
                    j++;
                }
                else if(i < push){
                    st.push(pushed[i]);
                    i++;
                }
                else 
                    return false;
            }
        }
        return true;
    }
};
