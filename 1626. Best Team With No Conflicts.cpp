class Solution {
public:

    int maxScore(int i, int j, vector<pair<int, int>>& res, vector<vector<int>>& dp){
        if(i >= res.size())
            return 0;

        if(dp[i][j+1] != -1)
            return dp[i][j+1];
        int currScore = res[i].second;

        int notSelected = maxScore(i+1, j, res, dp);
        if(j == -1 || res[j].second <= res[i].second){
            int selected = currScore + maxScore(i+1, i, res, dp);
            return dp[i][j+1] = max(selected, notSelected);
        }
        return dp[i][j+1] = notSelected;
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int ans = INT_MIN;
        int n = ages.size();
        vector<pair<int, int>> res(n);
        vector<vector<int>> dp(1002, vector<int> (1002, -1));
        
        for(int i=0;i<n;i++){
            res[i].first = ages[i];
            res[i].second = scores[i];
        }
        sort(res.begin(), res.end());

        return maxScore(0, -1, res, dp);
    }
};
