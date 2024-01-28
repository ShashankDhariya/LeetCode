class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> mat = matrix;
        for(int row=0;row<m;row++){
            for(int col=1;col<n;col++)
                mat[row][col] += mat[row][col-1];
        }

        int ans = 0;
        for(int colStart=0;colStart<n;colStart++){
            for(int colEnd=colStart;colEnd<n;colEnd++){
                for(int rowStart=0;rowStart<m;rowStart++){
                    int sum = 0;
                    for(int rowEnd=rowStart;rowEnd<m;rowEnd++){
                        sum += mat[rowEnd][colEnd] - (colStart? mat[rowEnd][colStart-1]: 0);
                        if(sum == target) 
                            ans++;
                    }
                }
            }
        }

        return ans;
    }
};
