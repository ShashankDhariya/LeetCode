class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> res;

        for(int i=0;i<n;i++){
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            res.push_back({dist, {points[i][0], points[i][1]}});
        }
        sort(res.begin(), res.end());

        vector<vector<int>> ans;
        for(auto num: res){
            if(!k)
                return ans;
            ans.push_back({num.second.first, num.second.second});
            k--;
        }
        return ans;
    }
};
