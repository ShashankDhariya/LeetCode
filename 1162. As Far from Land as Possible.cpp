class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        int dist = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)
                    q.push({i+1, j}), q.push({i-1, j}), q.push({i, j+1}), q.push({i, j-1});
            }
        }

        while(!q.empty()){
            int size = q.size();
            dist++;
            for(int a=0;a<size;a++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(i > -1 && j > -1 && i < m && j < n && grid[i][j] == 0){
                    grid[i][j] = dist;
                    q.push({i+1, j}), q.push({i-1, j}), q.push({i, j+1}), q.push({i, j-1});
                }
            }
        }
        return dist-1 <= 0? -1: dist - 1;
    }
};
