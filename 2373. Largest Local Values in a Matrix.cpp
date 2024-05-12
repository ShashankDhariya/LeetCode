class Solution {
public:

    vector<pair<int, int>> dir = {{0, 0}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0,-1}};
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> ans(n-2, vector<int> (n-2, 0));
        for(int i=1;i<n-1;i++){
            for(int j=1;j<n-1;j++){
                for(auto d: dir)
                    ans[i-1][j-1] = max(ans[i-1][j-1], grid[i+d.first][j+d.second]);
            }
        }

        return ans;
    }
};
