class Solution {
public:

    int solution(int idx, string& s, unordered_map<string, int>& d, vector<int>& dp){
        if(idx >= s.size())
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int ans = s.size();
        string res = "";
        for(int i=idx;i<s.size();i++){
            res += s[i];

            int ctr = (d.count(res))? 0: res.size();
            int rem = solution(i+1, s, d, dp);

            ans = min(ans, ctr + rem);
        }

        return dp[idx] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, int> d;
        for(auto& word: dictionary)
            d[word]++;

        vector<int> dp(s.length(), -1);
        return solution(0, s, d, dp);
    }
};
