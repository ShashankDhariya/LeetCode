class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int j=0;j<n;j++){
            for(int i=1;i<m;i++){
                if(matrix[i][j] != 0)
                    matrix[i][j] += matrix[i-1][j];
            }
        }

        int ans = -1;
        for(auto mat: matrix){
            vector<int> temp = mat;
            sort(temp.rbegin(), temp.rend());

            int s = temp[0];
            for(int i=0;i<n;i++){
                s = min(s, temp[i]);
                ans = max(ans, (i+1) * s);
            }
        }

        return ans;
    }
};
