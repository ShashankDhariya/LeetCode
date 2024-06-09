class Solution {
public:
    int mod = 1e9 + 7;
    int valueAfterKSeconds(int n, int k) {
        vector<int> dp(n, 1);
        for(int K=0;K<k;K++){    
            int sum = 0;
            for(int i=0;i<n;i++){
                sum = (sum + dp[i]) % mod;
                dp[i] = sum;
            }
        }

        return dp[n-1];
    }
};
