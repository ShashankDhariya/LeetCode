class Solution {
public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int> (n, 0));

        queue<pair<int, int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    mat[i][j] = -1;
                }
            }
        }

        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            dist++;
            for(int i=0;i<size;i++){
                int curr_row = q.front().first;
                int curr_col = q.front().second;
                q.pop();
                for(auto d: dir){
                    int row = curr_row + d.first;
                    int col = curr_col + d.second;
                    if(row < m && row > -1 && col < n && col > -1 && mat[row][col] != -1){
                        if(mat[row][col] == 1)
                            ans[row][col] = dist;
                        q.push({row, col});
                        mat[row][col] = -1;
                    }
                }
            }
        }
        return ans;
    }
};
