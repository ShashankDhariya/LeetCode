class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans += grid[i][j];
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && grid[i][j] == 1){
                    q.push({i, j});
                    grid[i][j] = -1;
                }
            }
        }

        while(!q.empty()){
            ans--;
            auto curr = q.front();
            int i = curr.first;
            int j = curr.second;
            q.pop();
            if(i+1 < n && grid[i+1][j] == 1){
                q.push({i+1, j});
                grid[i+1][j] = -1;
            }

            if(j+1 < m && grid[i][j+1] == 1){
                q.push({i, j+1});
                grid[i][j+1] = -1;
            }

            if(i-1 > 0 && grid[i-1][j] == 1){
                q.push({i-1, j});
                grid[i-1][j] = -1;
            }

            if(j-1 > 0 && grid[i][j-1] == 1){
                q.push({i, j-1});
                grid[i][j-1] = -1;
            }
        }
        return ans;
    }
};
