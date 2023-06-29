class Solution {
public:
    void solution(int ind, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int> res){
        if(target < 0)
            return;

        if(target == 0){
            ans.push_back(res);
            return;
        }

        int n = candidates.size();
        for(int i=ind;i<n;i++){
            if(i != ind && candidates[i] == candidates[i-1])
                continue;
            res.push_back(candidates[i]);
            solution(i+1, candidates, target-candidates[i], ans, res);
            res.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solution(0, candidates, target, ans, {});
        return ans;
    }
};
