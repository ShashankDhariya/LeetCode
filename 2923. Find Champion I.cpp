class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> res(n, 0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j)
                    continue;
                
                if(grid[i][j] == 1)
                    res[i]++;
                else
                    res[j]++;
            }
        }
        return max_element(res.begin(), res.end()) - res.begin();
    }
};
