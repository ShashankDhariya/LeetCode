class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> ans;
        
        for(auto str: s)
            ans.insert(str);
        return (int)ans.size();
    }
};
