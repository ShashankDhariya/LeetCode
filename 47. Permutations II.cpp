class Solution {
public:

    void solution(int& n, vector<int>& nums, vector<int> res, vector<bool> vis, set<vector<int>>& ans){
        if(res.size() == n){
            ans.insert(res);
            return;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i] = true;
                res.push_back(nums[i]);
                solution(n, nums, res, vis, ans);
                vis[i] = false;
                res.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;
        vector<bool> vis(n, false);
        solution(n, nums, {}, vis, ans);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};
