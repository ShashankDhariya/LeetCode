class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.rbegin(), coins.rend());

        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(auto coin: coins){
            for(int i=1;i<=amount;i++){
                if(coin <= i && dp[i-coin] != INT_MAX)
                    dp[i] = min(dp[i], 1+dp[i-coin]);
            }
        }
        return dp[amount] == INT_MAX? -1: dp[amount];
    }
};
