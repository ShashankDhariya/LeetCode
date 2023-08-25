class Solution {
public:

    bool solution(int i, int j, int k, string& s1, string& s2, string& s3, vector<vector<int>>& dp){        
        if(k == s3.length())
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(i < s1.length() && s3[k] == s1[i]){
            if(solution(i+1, j, k+1, s1, s2, s3, dp)) 
                return dp[i][j] = 1;
        }
    
        if(j < s2.length() && s3[k] == s2[j]){
            if(solution(i, j+1, k+1, s1, s2, s3, dp)) 
                return dp[i][j] = 1;
        }

        return dp[i][j] = 0;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        if(n + m != s3.length())
            return 0;

        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solution(0, 0, 0, s1, s2, s3, dp);
    }
};
