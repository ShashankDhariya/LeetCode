class Solution {
public:

    void combinations(int i, int& n, string& digits, string s, vector<string>& res, vector<string>& ans){
        if(s.length() == digits.length()){
            ans.push_back(s);
            return;
        }

        for(auto num: res[digits[i] - '0'])
            combinations(i+1, n, digits, s+num, res, ans);
    }

    vector<string> letterCombinations(string digits) {
        if(!digits.length())
            return {};

        int n = digits.size();
        vector<string> ans;

        vector<string> res = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        combinations(0, n, digits, "", res, ans);
        return ans;
    }
};
