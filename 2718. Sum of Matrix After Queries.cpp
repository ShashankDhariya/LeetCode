class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<bool> rows(n, 0);
        vector<bool> cols(n, 0);
        
        int size = queries.size();
        long long ans = 0;
        
        int nRows = n;
        int nCols = n;
        
        for(int i=size-1;i>-1;i--){       
            int idx = queries[i][1];
            long long val = queries[i][2];
            if(queries[i][0] == 0 && !rows[idx]){
                ans += (nCols*val);
                nRows--;
                rows[idx] = 1;
            }
            else if(queries[i][0] == 1 && !cols[idx]){
                ans += (nRows*val);
                nCols--;
                cols[idx] = 1;
            }
        }
        
        return ans;
    }
};
