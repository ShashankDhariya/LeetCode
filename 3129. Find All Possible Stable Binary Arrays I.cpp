class Solution {
public:
    int mod = 1e9 + 7;
    int solution(int one, int zero, int digit, int& limit, vector<vector<vector<int>>>& dp){
        if(one == 0 && zero == 0)
            return 1;

        if(dp[one][zero][digit] != -1)
            return dp[one][zero][digit];

        long long ans = 0;
        if(digit){
            for(int i=1;i<=min(limit, one);i++)
                ans = (ans + solution(one-i, zero, digit^1, limit, dp)) % mod;
        }

        else {
            for(int i=1;i<=min(limit, zero);i++)
                ans = (ans + solution(one, zero-i, digit^1, limit, dp)) % mod;
        }

        return dp[one][zero][digit] = ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>> dp(one+1, vector<vector<int>> (zero+1, vector<int> (2, -1)));
        return (1ll * solution(one, zero, 0, limit, dp) + solution(one, zero, 1, limit, dp)) % mod;
    }
};
