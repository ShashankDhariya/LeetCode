class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<int> dp(26, 0);

        int ans = 0;
        for(int i=0;i<n;i++){
            int len = 0;
            for(int j=0;j<26;j++){
                if(abs((s[i] - 'a') - j) <= k)
                    len = max(len, 1 + dp[j]);
            }

            dp[s[i] - 'a'] = len;
            ans = max(ans, dp[s[i] - 'a']);
        }

        return ans;
    }
};
