class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> dict;
        for(auto word: wordDict)
            dict.insert(word);

        vector<bool> dp(n+1, 0);
        dp[0] = 1;

        for(int i=1;i<=n;i++){
            for(int j=i-1;j>-1;j--){
                if(dp[j]){
                    string word = s.substr(j, i-j);
                    if(dict.find(word) != dict.end()){
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};
