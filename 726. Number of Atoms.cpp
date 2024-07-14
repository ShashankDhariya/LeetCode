class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> st;
        st.push({});

        int n = formula.length();
        int i = 0;
        while(i < n) {
            if(formula[i] == '('){
                st.push({});
                i++;
            }

            else if(formula[i] == ')'){
                auto top = st.top();
                st.pop();
                int idx = ++i;
                while(i < n && isdigit(formula[i]))
                    i++;

                int ctr = idx < i? stoi(formula.substr(idx, i - idx)): 1;   
                for(auto& t: top)
                    st.top()[t.first] += (t.second * ctr);
            }

            else {
                int idx = i++;
                while(i < n && islower(formula[i]))
                    i++;

                string ele = formula.substr(idx, i - idx);

                idx = i;
                while(i < n && isdigit(formula[i]))
                    i++;

                int ctr = idx < i? stoi(formula.substr(idx, i - idx)): 1;
                st.top()[ele] += ctr;
            }
        }

        map<string, int> top = st.top();
        string ans = "";
        for(auto t: top){
            ans += t.first;
            if(t.second > 1)
                ans += to_string(t.second);
        }

        return ans;
    }
};
