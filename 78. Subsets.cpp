class Solution {
public:

    void solution(int i, int n, vector<int>& nums, vector<int> res, set<vector<int>>& ans){
        ans.insert(res);
        if(i >= n)
            return;
        
        res.push_back(nums[i]);
        solution(i+1, n, nums, res, ans);
        res.pop_back();
        solution(i+1, n, nums, res, ans);        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;

        solution(0, n, nums, {}, ans);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};
