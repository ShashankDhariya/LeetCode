class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0)
            return -1;

        vector<vector<int>> dir = {{1,1}, {0,1}, {1,0}, {0,-1}, {-1,0}, {-1,-1}, {1,-1}, {-1,1}};
        int n = grid.size();
        queue<vector<int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int i = curr[0];
            int j = curr[1];

            if(i == n-1 && j == n-1)
                return grid[i][j];

            for(auto d: dir){
                int idx1 = i + d[0];
                int idx2 = j + d[1];

                if(idx1 < n && idx1 > -1 && idx2 < n && idx2 > -1 && !grid[idx1][idx2]){
                    grid[idx1][idx2] = grid[i][j] + 1;
                    q.push({idx1, idx2});
                }
            }
        }
        return -1;
    }
};
