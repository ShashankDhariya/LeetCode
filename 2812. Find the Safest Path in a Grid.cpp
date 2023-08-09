class Solution {
public:
    vector<pair<int, int>> dir = {{1,0}, {0,1}, {-1, 0}, {0, -1}};              
    
    bool isSafe(vector<vector<int>>& num, int safeDist){
        int n = num.size();
        
        if(num[0][0] < safeDist)
            return 0;
        
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool> (n, 0));
        
        q.push({0, 0});
        vis[0][0]= 1;
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x == n-1 && y == n-1)
                return 1;
            
            for(auto d: dir){
                int x_cor = x+d.first;
                int y_cor = y+d.second;

                if(x_cor < n && y_cor < n && x_cor > -1 && y_cor > -1 && vis[x_cor][y_cor] == 0){
                    if(num[x_cor][y_cor] < safeDist)
                        continue;
                    vis[x_cor][y_cor] = 1;
                    q.push({x_cor, y_cor});
                }
            }
        }
        return 0;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        
        vector<vector<bool>> vis(n, vector<bool> (n, 0));
        vector<vector<int>> disToThief(n, vector<int> (n, -1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                disToThief[x][y] = level;
                for(auto d: dir){
                    int x_cor = x+d.first;
                    int y_cor = y+d.second;
                    
                    if(x_cor < n && y_cor < n && x_cor > -1 && y_cor > -1 && vis[x_cor][y_cor] == 0){
                        vis[x_cor][y_cor] = 1;
                        q.push({x_cor, y_cor});
                    }
                }
            }
            level++;
        }
        
        int ans = 0;
        int left = 0;
        int right = level;
        while(left <= right){
            int mid = left + (right - left) / 2;
            
            if(isSafe(disToThief, mid)){
                ans = mid;
                left = mid + 1;
            }
            else 
                right = mid - 1;
        }
        
        return ans;
    }
};
