class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string str = s;
        reverse(s.begin(), s.end());

        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1] == str[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};
