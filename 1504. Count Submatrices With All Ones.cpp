class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

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
                        if(sum == ((rowEnd - rowStart + 1) * (colEnd - colStart + 1)))
                            ans++;
                    }
                }
            }
        }

        return ans;
    }
};
