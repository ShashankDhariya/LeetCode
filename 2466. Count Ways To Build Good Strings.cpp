#define MOD 1000000007
class Solution {
public:

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high+1, 0);
        dp[0] = 1;

        int ans = 0;
        for(int i=1;i<=high;i++){
            if(i >= zero)
                dp[i] += dp[i-zero] % MOD;

            if(i >= one)
                dp[i] += dp[i-one] % MOD;
            
            if(i >= low)
                ans = (ans + dp[i])%MOD;
        }

        return ans;
    }
};
