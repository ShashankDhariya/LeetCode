class Solution {
public:

    int solution(int i, int n, vector<vector<int>>& piles, int k, vector<vector<int>>& dp){
        if(dp[i][k] != -1)
            return dp[i][k];

        if(i >= n || k == 0)
            return 0;

        int res = solution(i+1, n, piles, k, dp);
        int curr = 0;

        for(int j=0;j<piles[i].size() && j<k;j++){
            curr += piles[i][j];
            res = max(res, solution(i+1, n, piles, k-j-1, dp) + curr);
        }
        dp[i][k] = res;
        return res;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n =  piles.size();
        vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
        return solution(0, n, piles, k, dp);
    }
};
