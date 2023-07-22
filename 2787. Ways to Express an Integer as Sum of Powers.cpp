class Solution {
public:
    
    int mod = 1e9 + 7;
    int solution(int curr, int n, int x, vector<vector<int>>& dp){
        if(n == 0)
            return 1;
        
        if(pow(curr, x) > n)
            return 0;
        
        if(dp[curr][n] != -1)
            return dp[curr][n];
        
        int taken = solution(curr + 1, n - pow(curr,x) , x, dp) % mod;
        int notTaken = solution(curr + 1, n, x, dp) % mod;
        
        return dp[curr][n] = (taken + notTaken) % mod;
    }
    
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solution(1, n, x, dp);
    }
};
