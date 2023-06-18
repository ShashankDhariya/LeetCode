class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis){
        if(vis[i][j] != -1)
            return vis[i][j];
        
        int up = 0;
        int down = 0;
        int left = 0;
        int right = 0;

        if(i-1 > -1 && grid[i][j] < grid[i-1][j])
            up = solve(i-1, j, grid, vis);
        if(i+1 < grid.size() && grid[i][j] < grid[i+1][j])
            down = solve(i+1, j, grid, vis);
        if(j-1 > -1 && grid[i][j] < grid[i][j-1])
            left = solve(i, j-1, grid, vis);
        if(j+1 < grid[0].size() && grid[i][j] < grid[i][j+1])
            right = solve(i, j+1, grid, vis);

        return vis[i][j] = (up + down + left + right) % mod + 1;
    }

    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, -1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j] != -1)
                    continue;
                else 
                    solve(i, j, grid, vis);
            }
        }

        int ans = 0;
        for(auto v: vis){
            for(auto a: v)
                ans = (ans + a) % mod;
        }
        return ans;
    }
};
