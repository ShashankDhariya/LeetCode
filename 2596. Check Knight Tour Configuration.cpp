class Solution {
public:
    
    void run(int i, int j, vector<vector<int>>& grid, int& ans){
        grid[i][j] = -1;
        ans++;
        
        if(i+1 < grid.size() && j+2 < grid[0].size() && grid[i+1][j+2] == ans && grid[i+1][j+2] != -1)
            run(i+1, j+2, grid, ans);
        
        else if(i+2 < grid.size() && j+1 < grid[0].size() && grid[i+2][j+1] == ans && grid[i+2][j+1] != -1)
            run(i+2, j+1, grid, ans);
        
        else if(i+2 < grid.size() && j-1 > -1 && grid[i+2][j-1] == ans && grid[i+2][j-1] != -1)
            run(i+2, j-1, grid, ans);
        
        else if(i+1 < grid.size() && j-2 > -1 && grid[i+1][j-2] == ans && grid[i+1][j-2] != -1)
            run(i+1, j-2, grid, ans);
        
        else if(i-1 > -1 && j-2 > -1 && grid[i-1][j-2] == ans && grid[i-1][j-2] != -1)
            run(i-1, j-2, grid, ans);
        
        else if(i-2 > -1 && j-1 > -1 && grid[i-2][j-1] == ans && grid[i-2][j-1] != -1)
            run(i-2, j-1, grid, ans);
        
        else if(i-2 > -1 && j+1 < grid[0].size() && grid[i-2][j+1] == ans && grid[i-2][j+1] != -1)
            run(i-2, j+1, grid, ans);
        
        else if(i-1 > -1 && j+2 < grid[0].size() && grid[i-1][j+2] == ans && grid[i-1][j+2] != -1)
            run(i-1, j+2, grid, ans);
    }
    
    bool checkValidGrid(vector<vector<int>>& grid) {
        int ans = 0;
        run(0, 0, grid, ans);
        for(auto g: grid){
            for(auto num: g){
                if(num != -1)
                    return false;
            }
        }
        return true;
    }
};
