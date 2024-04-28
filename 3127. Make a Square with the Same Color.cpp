class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                int w = 0;
                int b = 0;
                grid[i][j] == 'W'? w++: b++;
                grid[i][j+1] == 'W'? w++: b++;
                grid[i+1][j] == 'W'? w++: b++;
                grid[i+1][j+1] == 'W'? w++: b++;

                if(b >= 3 || w >= 3)
                    return 1;
            }
        }

        return 0;
    }
};
