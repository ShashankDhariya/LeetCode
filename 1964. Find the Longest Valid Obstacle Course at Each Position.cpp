class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n, 1);
        vector<int> res;
        res.push_back(obstacles[0]);

        for(int i=1;i<n;i++){
            if(res.back() <= obstacles[i]){
                res.push_back(obstacles[i]);
                ans[i] = res.size();
                continue;
            }
            int ind = upper_bound(res.begin(), res.end(), obstacles[i]) - res.begin();
            res[ind] = obstacles[i];
            ans[i] = ind + 1;
        }
        return ans;
    }
};
