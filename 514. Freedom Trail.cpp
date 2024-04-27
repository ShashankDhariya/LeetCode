class Solution {
public:

    int solution(int i, int j, int& n, string& ring, string& key, vector<vector<int>>& dp){
        if(j == key.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 1e9;
        for(int idx=0;idx<n;idx++){
            if(ring[idx] == key[j]){
                int res = 1 + min(abs(i - idx), n - abs(i - idx));
                ans = min(ans, res + solution(idx, j+1, n, ring, key, dp));
            }
        }

        return dp[i][j] = ans;
    }

    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        vector<vector<int>> dp(n, vector<int> (key.size(), -1));
        return solution(0, 0, n, ring, key, dp);
    }
};
