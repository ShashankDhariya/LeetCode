class Solution {
private:
    
    void bfs(int row, int col,vector<vector<int>>& vis,vector<vector<char>>& grid){
        vis[row][col] = 1;
        
        queue<pair<int, int>> q;
        q.push({row, col});
        
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()){
            
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow;
                int ncol;
                if(i == 0){
                    nrow = row-1;
                    ncol = col;
                }
                else if(i == 2){
                    nrow = row+1;
                    ncol = col;
                }
                
                else if(i == 3){
                    nrow = row;
                    ncol = col+1;
                }
                
                else{
                    nrow = row;
                    ncol = col-1;
                }
                    
                if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }      
        }        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int res = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    bfs(i,j,vis,grid);
                    res++;
                }
            }
        }
        return res;
    }
};
