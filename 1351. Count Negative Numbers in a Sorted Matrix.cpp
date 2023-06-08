class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int i = 0;
        int j = cols-1;

        while(i < rows && j > -1){
            if(grid[i][j] < 0){
                ans += (rows-i);
                j--;
            }
            else 
                i++;
        }
        return ans;
    }
};
