class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> maxi(n);
        for(int j=0;j<n;j++){
            int mm = -1e5;
            for(int i=0;i<m;i++)
                mm = max(mm, matrix[i][j]);
            maxi[j] = mm;
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == -1)
                    matrix[i][j] = maxi[j];
            }
        }
        
        return matrix;
    }
};
