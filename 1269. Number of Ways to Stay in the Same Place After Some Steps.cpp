class Solution {
public:
    int mod = 1e9+7;
    int solution(int i, int steps, int arrLen, vector<vector<int>>& dp){
        if(i < 0 || i >= arrLen)
            return 0;
        
        if(steps == 0){
            if(i == 0)
                return 1;
            else 
                return 0;
        }

        if(dp[i][steps] != -1)
            return dp[i][steps];

        int right = solution(i+1, steps-1, arrLen, dp) % mod;
        int left = solution(i-1, steps-1, arrLen, dp) % mod;
        int stay = solution(i, steps-1, arrLen, dp) % mod;

        return dp[i][steps] = ((long long)right + (long long)left + stay) % mod;
    }

    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps+1, vector<int> (steps+1, -1));
        return solution(0, steps, arrLen, dp);
    }
};
