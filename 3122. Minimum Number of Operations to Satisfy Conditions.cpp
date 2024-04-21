class Solution {
public:
    
    int solution(int i, int& m, int& n, int chosen, vector<vector<int>>& res, vector<vector<int>>& dp){
        if(i == n)
            return 0;
        
        if(dp[i][chosen+1] != -1)
            return dp[i][chosen+1];
        
        int ans = 1e9;
        for(int num=0;num<10;num++){
            if(chosen == num)
                continue;
            
            int r = (m - res[i][num]) + solution(i+1, m, n, num, res, dp);
            ans = min(ans, r);
        }
        
        return dp[i][chosen+1] = ans;
    }
    
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> res(n, vector<int> (10, 0));
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++)
                res[j][grid[i][j]]++;
        }
        
        vector<vector<int>> dp(n, vector<int> (2048, -1));
        return solution(0, m, n, -1, res, dp);
    }
};
