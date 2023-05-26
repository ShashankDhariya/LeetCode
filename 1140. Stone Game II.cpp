class Solution {
public:

    int solution(int i, int m, vector<int>& suffixSum, vector<int>& piles, vector<vector<int>>& dp){
        if(i >= piles.size())
            return 0;

        if(i + 2*m >= piles.size())
            return suffixSum[i];

        if(dp[i][m] != -1)
            return dp[i][m];

        int ans = 0;
        for(int x=1;x<=2*m;x++)
            ans = max(ans, suffixSum[i] - solution(i+x, max(m, x), suffixSum, piles, dp));

        return dp[i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));

        vector<int> suffixSum(n, 0);
        suffixSum[n-1] = piles[n-1];
        for(int i=n-2;i>=0;i--)
            suffixSum[i] = suffixSum[i+1] + piles[i];

        return solution(0, 1, suffixSum, piles, dp);
    }
};
