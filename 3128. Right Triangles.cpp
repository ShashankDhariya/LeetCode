class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }

        long long ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j])
                    continue;

                ans += 1ll*(row[i] - 1) * (col[j] - 1);
            }
        }

        return ans;
    }
};
