class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string ans = "";
        int ind = 0;

        for(int i=0;i<n;i++){
            if(ind - 2 > -1 && ans[ind-2] == s[i] && ans[ind-1] == s[i])
                continue;
            else {
                ans.push_back(s[i]);
                ind++;
            }
        }
        return ans;
    }
};
