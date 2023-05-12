class Solution {
public:

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1, 0);

        for(int i=n-1;i>-1;i--){
            int point = questions[i][0];
            int jump = questions[i][1];
            
            int ind = min(n, i+1+jump);
            dp[i] = max(dp[i+1], point + dp[ind]);
        }
        return dp[0];
    }
};
