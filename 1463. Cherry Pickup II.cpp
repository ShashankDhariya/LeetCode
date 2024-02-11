class Solution {
public:

    vector<int> dir = {-1, 0, 1};
    int solution(int i, int j1, int j2, int& m, int& n, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if(i == m || j1 < 0 || j2 < 0 || j1 == n || j2 == n)
            return 0;

        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int res = j1 == j2?  grid[i][j2]: grid[i][j1] + grid[i][j2];

        int ans = 0;
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++)
                ans = max(ans, res + solution(i + 1, j1 + dir[j], j2+ dir[k], m, n, grid, dp));
        }

        return dp[i][j1][j2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (n, -1)));
        return solution(0, 0, n-1, m, n, grid, dp);
    }
};
