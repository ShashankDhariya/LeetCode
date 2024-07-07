class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> X(m, vector<int> (n, 0));
        vector<vector<int>> Y(m, vector<int> (n, 0));
        
        int ans = 0;
        for(int i=0;i<m;i++){
            int x = 0;
            int y = 0;
            for(int j=0;j<n;j++){
                if(grid[i][j] == 'X') 
                    x++;
                else if(grid[i][j] == 'Y') 
                    y++;
                
                int prevX = i-1 > -1? X[i-1][j]: 0;
                int prevY = i-1 > -1? Y[i-1][j]: 0;
                
                if((x + prevX) && (x + prevX) == (y + prevY))
                    ans++;
                
                X[i][j] = x + prevX;
                Y[i][j] = y + prevY;
            }
        }
        
        return ans;
    }
};
