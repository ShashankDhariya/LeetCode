class Solution {
public:

    pair<int, int> bfs(int i, int j, int& m, int& n, vector<vector<bool>>& vis, vector<vector<int>>& land){
        queue<pair<int, int>> q;
        q.push({i, j});

        pair<int, int> last = {i, j};
        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            int row = curr.first;
            int col = curr.second;
            if(vis[row][col])
                continue;

            last.first = max(last.first, row);
            last.second = max(last.second, col);

            vis[row][col] = 1;
            if(row+1 < m && land[row+1][col] == 1 && vis[row+1][col] == 0)
                q.push({row+1, col});

            if(col+1 < n && land[row][col+1] == 1 && vis[row][col+1] == 0)
                q.push({row, col+1});
        }

        return last;
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int m = land.size();
        int n = land[0].size();
        
        vector<vector<bool>> vis(m, vector<bool> (n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j] == 0 || vis[i][j])
                    continue;

                pair<int, int> res = bfs(i, j, m, n, vis, land);
                ans.push_back({i, j, res.first, res.second});
            }
        }

        return ans;
    }
};
