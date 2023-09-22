class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> mp1(m, 0);
        vector<int> mp2(n, 0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1){
                    mp1[i]++;
                    mp2[j]++;
                }
            }
        }

        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1 && mp1[i] == 1 && mp2[j] == 1)
                    ans++;
            }
        }

        return ans;
    }
};
