class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];

        for(int i=1;i<strs.size();i++){
            string res = "";
            for(int j=0;j<min(strs[i].length(), ans.length());j++){
                if(ans[j] == strs[i][j])
                    res.push_back(strs[i][j]);
                else 
                    break;
            }
            if(res == "")
                return "";
            ans = res;
        }
        return ans;
    }
};
