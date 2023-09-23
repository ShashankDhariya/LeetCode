class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b){
            return a.size() < b.size();
        });

        int ans = 0;
        unordered_map<string, int> dp;
        for(auto word: words){
            for(int i=0;i<word.size();i++){
                string str = word.substr(0, i) + word.substr(i+1);
                dp[word] = max(dp[word], dp[str] + 1);
            }
            ans = max(ans, dp[word]);
        }

        return ans;
    }
};
