class Solution {
public:
    bool solution(int i, int j, int& m, int& n, string& s, string& p, vector<vector<int>>& dp) {
        if(i == m && j == n)
            return 1;

        if(i < m && j == n)
            return 0;

        if(i == m && j < n){
            for(int k=j;k<n;k++){
                if(p[k] != '*')
                    return 0;
            }

            return 1;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == p[j] || p[j] == '?')
            return dp[i][j] = solution(i+1, j+1, m, n, s, p, dp);

        if(p[j] == '*')
            return dp[i][j] = (solution(i, j+1, m, n, s, p, dp) || solution(i+1, j, m, n, s, p, dp));

        return dp[i][j] = 0;
    }

    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solution(0, 0, m, n, s, p, dp);
    }
};
