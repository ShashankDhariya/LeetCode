class Solution {
public:

    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                dp[i][j] = (j == 0? 0: dp[i][j-1]) + (matrix[i][j] - '0');
        }

        for(int startCol=0;startCol<n;startCol++){
            for(int endCol=startCol;endCol<n;endCol++){
                int res = 0;
                int prev = -1;
                for(int startRow=0;startRow<m;startRow++){
                    res += dp[startRow][endCol] - (startCol == 0? 0: dp[startRow][startCol-1]);
                    int area = (endCol - startCol + 1) * (startRow - prev);
                    if(res == area) 
                        ans = max(ans, area);
                
                    else {
                        res = 0;
                        prev = startRow;
                    }
                }
            }
        }

        return ans;
    }
};
