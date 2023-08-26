class Solution {
public:

    int solution(int idx, int n, vector<int>& res, vector<vector<int>>& pairs, vector<int>& dp) {
        if(idx == n)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];

        int ind = upper_bound(res.begin(), res.end(), pairs[idx][1]) - res.begin();
        int pick = 1 + solution(ind, n, res, pairs, dp);
        int notPick = solution(idx+1, n, res, pairs, dp);

        return dp[idx] = max(pick, notPick);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());

        int n = pairs.size();
        vector<int> res;
        for(auto pair: pairs)
            res.push_back(pair[0]);

        vector<int> dp(n, -1);
        return solution(0, n, res, pairs, dp);
    }
};
