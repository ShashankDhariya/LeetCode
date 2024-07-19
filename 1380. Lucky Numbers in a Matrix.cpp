class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;

        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            int mini = 0;
            for(int j=0;j<n;j++){
                if(matrix[i][j] < matrix[i][mini])
                    mini = j;
            }

            int maxi = -1;
            for(int i=0;i<m;i++)
                maxi = max(maxi, matrix[i][mini]);
            
            if(maxi == matrix[i][mini])
                ans.push_back(maxi);
        }

        return ans;
    }
};
