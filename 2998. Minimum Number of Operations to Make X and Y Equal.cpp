class Solution {
public:
    
    int solution(int x, int y, vector<int>& dp){
        if(x <= y)
            return y - x;
        
        if(dp[x] != -1)
            return dp[x];
        
        int ans = x - y;
        ans = min(ans, 1 + x%5 + solution(x/5, y, dp));
        ans = min(ans, 1 + (5 - x%5) + solution(x/5 + 1, y, dp));
        ans = min(ans, 1 + x%11 + solution(x/11, y, dp));
        ans = min(ans, 1 + (11 - x%11) + solution(x/11 + 1, y, dp));
        
        return dp[x] = ans;
    }
    
    int minimumOperationsToMakeEqual(int x, int y) {
        vector<int> dp(10011, -1);
        return solution(x, y, dp);
    }
};
