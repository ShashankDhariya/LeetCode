class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = INT_MAX;

        pair<int, int> min1 = {0, -1};
        pair<int, int> min2 = {0, -1};
        for(int i=0;i<n;i++){
            pair<int, int> currMin1 = {INT_MAX, -1};
            pair<int, int> currMin2 = {INT_MAX, -1};
            for(int j=0;j<n;j++){
                auto minRes = (j != min1.second? min1: min2);

                if(grid[i][j] + minRes.first < currMin1.first){
                    currMin2 = currMin1;
                    currMin1 = {minRes.first + grid[i][j], j};
                }
                else if(grid[i][j] + minRes.first < currMin2.first)
                    currMin2 = {minRes.first + grid[i][j], j};
                
                if(i == n-1)
                    ans = min({ans, currMin1.first, currMin2.first});
            }

            min1 = currMin1;
            min2 = currMin2;
        }

        return ans;
    }
};
