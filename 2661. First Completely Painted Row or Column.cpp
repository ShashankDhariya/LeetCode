class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int size = arr.size();
        int m = mat.size();
        int n = mat[0].size();
        
        unordered_map<int, pair<int, int>> mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                mp[mat[i][j]] = {i, j};
        }
        
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        
        for(int i=0;i<size;i++){
            rows[mp[arr[i]].first]++;
            cols[mp[arr[i]].second]++;
            if(rows[mp[arr[i]].first] == n)
                return i;
            if(cols[mp[arr[i]].second] == m)
                return i;
        }
        return -1;
    }
};
