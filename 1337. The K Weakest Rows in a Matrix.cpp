class Solution {
public:

    int countSoldier(vector<int>& res, int n){
        int i = 0;
        int j = n - 1;

        while(i <= j){
            int mid = i + (j-i)/2;
            if(res[mid] == 1)
                i = mid + 1;
            else 
                j = mid - 1;
        }
        return i;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<pair<int, int>> res;
        for(int i=0;i<m;i++){
            int s = countSoldier(mat[i], n);
            res.push_back({s, i});
        }

        sort(res.begin(), res.end(), [](pair<int, int>& a, pair<int, int>& b){
            if(a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        });

        vector<int> ans;
        for(int i=0;i<k;i++)
            ans.push_back(res[i].second);

        return ans;
    }
};
