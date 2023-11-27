class Solution {
public:
    int mod = 1e9 + 7;
    int knightDialer(int n) {
        vector<vector<int>> res = {{4,6}, {6,8}, {7,9}, {4,8}, {3,9,0}, {}, {1,7,0}, {2,6}, {1,3}, {2,4}};

        vector<vector<int>> dp(n, vector<int> (10, 0));
        for(int i=0;i<10;i++)
            dp[0][i] = 1;

        for(int i=1;i<n;i++){
            for(int j=0;j<10;j++){
                int ans = 0;
                for(auto r: res[j])
                    ans = (ans + dp[i-1][r]) % mod;
                
                dp[i][j] = ans;
            }
        }

        int ans = 0;
        for(int i=0;i<10;i++)
            ans = (ans + dp[n-1][i]) % mod;
        return ans;
    }
}; 
