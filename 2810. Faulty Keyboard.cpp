class Solution {
public:
    string finalString(string s) {
        string ans = "";
        for(auto str: s){
            if(str == 'i')
                reverse(ans.begin(), ans.end());
            else
                ans += str;
        }
        return ans;
    }
};
