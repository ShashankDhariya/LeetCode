class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> rows;

        for(int i=0;i<n;i++)
            rows[grid[i]]++;

        int ans = 0;
        for(int j=0;j<n;j++){
            vector<int> cols(n);
            for(int i=0;i<n;i++)
                cols[i] = grid[i][j];
            
            ans += rows[cols];
        }
        return ans;
    }
};
