class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k %= n;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i % 2 == 0){
                    if(mat[i][j] != mat[i][(j+k) % n])
                        return 0;
                }
                else {
                    if(mat[i][j] != mat[i][(n-k+j) % n])
                        return 0;
                }
            }
        }
        
        return 1;
    }
};
