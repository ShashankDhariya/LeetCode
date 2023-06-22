class Solution {
public:

    int market(int i, bool buy, vector<int>& prices, int fee, vector<vector<int>>& dp){
        if(i >= prices.size())
            return 0;

        if(dp[i][buy] != -1)
            return dp[i][buy];

        int profitBuy = 0;
        int profitSell = 0;
        if(buy)
            profitBuy = max(market(i+1, 1, prices, fee, dp), -prices[i] + market(i+1, 0, prices, fee, dp));
        else
            profitSell = max(market(i+1, 0, prices, fee, dp), prices[i] - fee + market(i+1, 1, prices, fee, dp));
        return dp[i][buy] = max(profitBuy, profitSell);
    }

    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return market(0, 1, prices, fee, dp);
    }
};
