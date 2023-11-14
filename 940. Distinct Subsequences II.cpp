class Solution {
public:
    int mod = 1e9+7;
    int distinctSubseqII(string s) {
        int n = s.length();
        vector<int> dp(n+1, 1);
        vector<int> last(26, -1);

        for(int i=1;i<=n;i++){
            if(last[s[i-1] - 'a'] != -1)
                dp[i] = ((2 * 1LL * dp[i-1]) % mod - dp[last[s[i-1] - 'a'] - 1]) % mod;

            else 
                dp[i] = ((2 * 1LL * dp[i-1])) % mod;
                
            last[s[i-1] - 'a'] = i;
        }
        if(dp[n] <= 0)
            dp[n] += mod;

        return dp[n] - 1;
    }
};
