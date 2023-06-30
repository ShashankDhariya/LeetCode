class Solution {
public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool bfs(int rows, int cols, vector<vector<int>>& cells, int currDay){
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(rows, vector<bool> (cols, 0));

        for(int i=0;i<currDay;i++)
            vis[cells[i][0] - 1][cells[i][1] - 1] = 1;

        for(int i=0;i<cols;i++){
            if(vis[0][i] == 0){
                q.push({0, i});
                vis[0][i] = 1;
            }
        }
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(curr.first == rows - 1)
                return 1;
            for(auto& d: dir){
                int i = curr.first + d.first;
                int j = curr.second + d.second;
                if(i < rows && j < cols && i > -1 && j > -1 && vis[i][j] == 0){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        return 0;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size();
        int left = 0;
        int right = n - 1;
        int ans = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(bfs(row, col, cells, mid)){
                ans = mid;
                left = mid + 1;
            }
            else 
                right = mid - 1;
        }
        return ans;
    }
};
