class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        int ctr = 0;
        int open = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                ctr++;
                open++;
                ans.push_back(s[i]);
            }

            else if(s[i] == ')'){
                if(ctr == 0)
                    continue;
                else {
                    ctr--;
                    ans.push_back(s[i]);
                }
            }

            else 
                ans.push_back(s[i]);
        }

        string res = "";
        int no = open - ctr;
        for(auto a: ans){
            if(a == '('){
                if(no > 0)
                    no--;
                else
                    continue;
            }

            res += a;
        }

        return res;
    }
};
