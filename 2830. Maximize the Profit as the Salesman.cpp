class Solution {
public:
    
    int profit(int i, vector<vector<int>>& offers, vector<int>& res, vector<int>& dp){
        if(i >= offers.size())
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int pick = 0;
        int idx = upper_bound(res.begin(), res.end(), offers[i][1]) - res.begin();
        pick = offers[i][2] + profit(idx, offers, res, dp);
        
        int notPick = profit(i+1, offers, res, dp);
        
        return dp[i] = max(pick, notPick);
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> dp(offers.size(), -1);
        sort(offers.begin(), offers.end(), [](vector<int> &a, vector<int>& b){
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        
        vector<int> res;
        for(auto offer: offers)
            res.push_back(offer[0]);
        
        return profit(0, offers, res, dp);
    }
};
