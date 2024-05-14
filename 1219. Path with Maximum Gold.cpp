class Solution {
public:

    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int solution(int i, int j, int& m, int& n, vector<vector<int>>& grid){
        if(i < 0 || i == m || j < 0 || j == n || grid[i][j] == 0)
            return 0;

        int gold = grid[i][j];
        grid[i][j] = 0;

        int ans = 0;
        for(auto d: dir){
            int x = i + d.first;
            int y = j + d.second;
            ans = max(ans, gold + solution(x, y, m, n, grid));
        }

        grid[i][j] = gold;
        return ans;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                ans = max(ans, solution(i, j, m, n, grid));
        }

        return ans;
    }
};
