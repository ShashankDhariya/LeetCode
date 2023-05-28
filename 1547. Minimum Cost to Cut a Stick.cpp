class Solution {
public:

    int solution(int s, int e, vector<int>& cuts, int left, int right, vector<vector<int>>& dp){
        if(left > right)
            return 0;

        if(dp[left][right] != -1)
            return dp[left][right];

        int ans = INT_MAX; 
        for(int i=left;i<=right;i++){
            int first_part = solution(s, cuts[i], cuts, left, i-1, dp);
            int second_part = solution(cuts[i], e, cuts, i+1, right, dp);
            int cost = e - s + first_part + second_part;
            ans = min(ans, cost);
        }
        return dp[left][right] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>> dp(101, vector<int> (101, -1));
        sort(cuts.begin(), cuts.end());
        return solution(0, n, cuts, 0, cuts.size()-1, dp);
    }
};
