class Solution {
public:
    vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, queue<pair<int, int>>& q){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || vis[i][j] || grid[i][j] == 0)
            return;

        vis[i][j] = 1;
        q.push({i, j});
        for(auto& d: dir)
            dfs(i+d[0], j+d[1], grid, vis, q);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        bool b = false;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    dfs(i, j, grid, vis, q);
                    b = true;
                    break;
                }
            }
            if(b)
                break;
        }

        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            for(int a=0;a<size;a++){
                auto curr = q.front();
                q.pop();

                for(auto& d: dir){
                    int i = curr.first + d[0];
                    int j = curr.second + d[1];
                    if(i >= 0 && j >= 0 && i < n && j < n && !vis[i][j]){
                        if(grid[i][j])
                            return ans;
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
