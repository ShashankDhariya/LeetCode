class Solution {
public:

    int solution(int i, int j, string& s, vector<vector<int>>& dp){
        if(i == j)
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        for(int k=i;k<j;k++)
            ans = min(ans, solution(i, k, s, dp) + solution(k+1, j, s, dp));
        
        return dp[i][j] = s[i] == s[j]? ans - 1: ans;
    }

    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solution(0, n-1, s, dp);
    }
};
