class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        stack<string> st;

        for(int i=0;i<n;i++){
            if(path[i] == '/')
                continue;

            string str = "";
            while(i < n && path[i] != '/')
                str += path[i++];
            
            if(str == ".."){
                if(!st.empty())
                    st.pop();
            }

            else if(str != ".")
                st.push(str);
        }

        string ans = "";
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }

        if(!ans.size())
            ans += "/";
        return ans;
    }
};
