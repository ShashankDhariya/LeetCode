class Solution {
public:

    int remain(int i, string& s, int n){
        int sum = 0;
        for(;i<n;i++)
            sum += s[i];
        return sum;
    }

    int solution(int i, int j, int& m, int& n, string& s1, string& s2, vector<vector<int>>& dp){
        if(i == m || j == n){
            if(i == m && j == n)
                return 0;
            return (i == m)? remain(j, s2, n): remain(i, s1, m);
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j])
            dp[i][j] = solution(i+1, j+1, m, n, s1, s2, dp);

        else
            dp[i][j] = min(s1[i] + solution(i+1, j, m, n, s1, s2, dp), s2[j] + solution(i, j+1, m, n, s1, s2,dp)); 

        return dp[i][j];
    }

    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solution(0, 0, m, n, s1, s2, dp);
    }
};
