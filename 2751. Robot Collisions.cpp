class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<vector<int>> res;

        int n = healths.size();
        for(int i=0;i<n;i++)
            res.push_back({positions[i], healths[i], i});

        sort(res.begin(), res.end());

        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(directions[res[i][2]] == 'R')
                st.push(i);

            else {
                int size = st.size();
                while(!st.empty() && res[st.top()][1] < res[i][1]) {
                    st.pop();
                    res[i][1]--;
                }

                if(st.empty())
                    ans[res[i][2]] = res[i][1];

                else {
                    if(res[st.top()][1] == res[i][1])
                        st.pop();

                    else 
                        res[st.top()][1]--;
                }
            }
        }

        while(!st.empty()){
            ans[res[st.top()][2]] = res[st.top()][1];
            st.pop();
        }

        int idx = 0;
        for(int i=0;i<n;i++){
            if(ans[i])
                ans[idx++] = ans[i];
        }

        ans.resize(idx);
        return ans;
    }
};
