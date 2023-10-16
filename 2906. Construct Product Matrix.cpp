class Solution {
public:
    int mod = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long> up(n, 1);
        vector<long> down(n, 1);
        
        vector<vector<long>> rSum(n, vector<long> (m, 1));
        vector<vector<long>> lSum(n, vector<long> (m, 1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                lSum[i][j] = (grid[i][j] * (j-1 > -1? lSum[i][j-1]: 1)) % mod;
                rSum[i][m-j-1] = (grid[i][m-j-1] * (m-j < m? rSum[i][m-j]: 1)) % mod;
                
                up[i] = (up[i] * grid[i][j]) % mod;
                down[n-i-1] = (down[n-i-1] * grid[n-i-1][j]) % mod;
            }
            if(i-1 > -1)
                up[i] = (up[i] * up[i-1]) % mod;
            
            if(n-i < n)
                down[n-i-1] = ((long long)down[n-i-1] * down[n-i]) % mod;
        }

        vector<vector<int>> ans(n, vector<int> (m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int prev = 1;
                int next = 1;
                if(i-1 > -1)
                    prev = up[i-1];
                if(i+1 < n)
                    next = down[i+1];
                
                long left = 1;
                long right = 1;
                
                if(j-1 > -1)   left = lSum[i][j-1];
                if(j+1 < m)    right = rSum[i][j+1];
                      
                ans[i][j] = ((long long)prev * left * right * next) % mod;
            }
        }
        return ans;
    }
};
