class Solution {
public:

    double solution(int a, int b, vector<vector<double>>& dp){
        if(a <= 0 && b <= 0)
            return 0.5;

        if(b <= 0)
            return 0;

        if(a <= 0)
            return 1;        

        if(dp[a][b] != -1)
            return dp[a][b];

        double op1 = solution(a - 100, b, dp) / 4.0;
        double op2 = solution(a - 75, b - 25, dp) / 4.0;
        double op3 = solution(a - 50, b - 50, dp) / 4.0;
        double op4 = solution(a - 25, b - 75, dp) / 4.0;

        return dp[a][b] = op1 + op2 + op3 + op4;
    }

    double soupServings(int n) {
        if(n >= 4800)
            return 1;
        vector<vector<double>> dp(n+1, vector<double> (n+1, -1));
        return solution(n, n, dp);
    }
};
