class Solution {
public:

    void solution(int n, vector<int>& nums, unordered_set<int> s, vector<int> res, vector<vector<int>>& ans){
        if(res.size() == n){
            ans.push_back(res);
            return;
        }

        for(int i=0;i<n;i++){
            if(s.find(nums[i]) == s.end()){
                s.insert(nums[i]);
                res.push_back(nums[i]);
                solution(n, nums, s, res, ans);
                res.pop_back();
                s.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        unordered_set<int> s;
        solution(n, nums, s, {}, ans);
        return ans;
    }
};
