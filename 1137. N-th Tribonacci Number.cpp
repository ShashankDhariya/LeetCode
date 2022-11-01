class Solution {
public:
    int series(int n, vector<int>& dp){
        if(n < 2)
            return n;
        if(n == 2)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];

        dp[n] =  series(n - 1, dp) + series(n - 2, dp) + series(n - 3, dp);
        return dp[n];
    }
    
    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return series(n, dp);
    }
};

/*
  OR 
  class Solution {
public:
    int tribonacci(int n) {
        if(n <= 1)
            return n;

        vector<int> dp(n+1, -1);
        dp[0] = 0, dp[1] = 1, dp[2] = 1;

        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        return dp[n];
    }
};
*/
