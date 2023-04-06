class Solution {
public:

    void dfs(int i, int j, int m, int n, vector<vector<int>>& grid){
        grid[i][j] = -1;
        if(i+1 < m && grid[i+1][j] == 0)
            dfs(i+1, j, m, n, grid);
        if(j+1 < n && grid[i][j+1] == 0)
            dfs(i, j+1, m, n, grid);
        if(i-1 > -1 && grid[i-1][j] == 0)
            dfs(i-1, j, m, n, grid);
        if(j-1 > -1 && grid[i][j-1] == 0)
            dfs(i, j-1, m, n, grid);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            if(grid[i][0] == 0)
                dfs(i, 0, m, n, grid);
            if(grid[i][n-1] == 0)
                dfs(i, n-1, m, n, grid);
        }

        for(int i=0;i<n;i++){
            if(grid[0][i] == 0)
                dfs(0, i, m, n, grid);
            if(grid[m-1][i] == 0)
                dfs(m-1, i, m, n, grid);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == -1 || grid[i][j] == 1)
                    continue;
                dfs(i, j, m, n, grid);
                ans++;
            }
        }
        return ans;
    }
};
