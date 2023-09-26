class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIdx(26, -1);
        int n = s.length();
        for(int i=0;i<n;i++)
            lastIdx[s[i] - 'a'] = i;
        
        stack<int> st;
        vector<bool> vis(26, 0);
        for(int i=0;i<n;i++){
            if(vis[s[i] - 'a'] == 1)
                continue;
                
            while(!st.empty() && st.top() > s[i] && i < lastIdx[st.top() - 'a']){
                vis[st.top() - 'a'] = 0;
                st.pop();
            }

            st.push(s[i]);
            vis[s[i] - 'a'] = 1;
        }

        string ans = "";
        while(!st.empty()){
            ans += (char)st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
