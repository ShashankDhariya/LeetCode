class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        for(int gap=0;gap<n;gap++){
            for(int i=0, j=gap;j<n;i++, j++){
                if(gap == 0)
                    dp[i][j] = true;
                
                else if(gap == 1)
                    dp[i][j] = (s[i] == s[j]);
                
                else if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1];
                
                if(dp[i][j]){
                    ans = s.substr(i, gap+1);
                }
            }
        }
        return ans;
    }
};
