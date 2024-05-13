class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> col(n, 0);
        for(int i=0;i<m;i++){
            bool change = 0;
            if(grid[i][0] == 0)
                change = 1;

            for(int j=0;j<n;j++){
                if(change)
                    grid[i][j] = !grid[i][j];

                col[j] += grid[i][j];
            }
        }

        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                if(col[j] < (m+1) / 2)
                    grid[i][j] = !grid[i][j];
            }
        }

        int ans = 0;
        for(int i=0;i<m;i++){
            int res = 0;
            for(int j=0;j<n;j++){
                cout<<grid[i][j] << " ";
                if(grid[i][j])
                    res |= (1 << (n-j-1));
            }
            cout<<endl;
            ans += res;
        }

        return ans;
    }
};
