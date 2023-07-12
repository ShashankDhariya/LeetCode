class Solution {
public:

    void solution(int curr, int n, int k, vector<int> res, vector<vector<int>>& ans){
        if(curr > n)
            return;

        if(k == 0){
            ans.push_back(res);
            return;
        }

        for(int i=curr+1;i<=n;i++){
            res.push_back(i);
            solution(i, n, k-1, res, ans);
            res.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        solution(0, n, k, {}, ans);
        return ans;
    }
};
