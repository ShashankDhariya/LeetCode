class Solution {
public:

    int solution(int i, vector<int>& stoneValue, vector<int>& dp){
        int n = stoneValue.size();
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];
        
        int one = 0;
        one = stoneValue[i] - solution(i+1, stoneValue, dp);

        int two = INT_MIN;
        if(i+1 < n)
        two = stoneValue[i] + stoneValue[i+1] - solution(i+2, stoneValue, dp);

        int three = INT_MIN;
        if(i+2 < n)
            three = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - solution(i+3, stoneValue, dp);

        return dp[i] = max({one, two, three});
    }

    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size(), -1);
        int res =  solution(0, stoneValue, dp);
        if(res == 0)
            return "Tie";
        return res>0? "Alice": "Bob";
    }
};
