class Solution {
public:
    vector<pair<int, int>> dir = {{-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}};
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> ans(m, vector<int> (n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum = img[i][j];
                int num = 1;
                for(auto d: dir){
                    int x = i + d.first;
                    int y = j + d.second;
                    if(x > -1 && x < m && y > -1 && y < n){
                        sum += img[x][y];
                        num++;
                    }
                }
                ans[i][j] = sum / num;
            }
        }

        return ans;
    }
};
