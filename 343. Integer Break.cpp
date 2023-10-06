class Solution {
public:
    int solution(int n, int k, vector<int>& dp){
        if(n == 0)
            return k > 1;
        
        if(n < 0)
            return 0;

        if(dp[n] != -1)
            return dp[n];

        int ans = 0;
        for(int i=1;i<=n;i++){
            int res = i * solution(n-i, k+1, dp);
            ans = max(ans, res);
        }
        return dp[n] = ans;
    }

    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        return solution(n, 0, dp);
    }
};
