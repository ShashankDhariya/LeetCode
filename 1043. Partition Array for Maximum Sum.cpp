class Solution {
public:

    int solution(int idx, int n, vector<int>& arr, int& k, vector<int>& dp){
        if(idx == arr.size())
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int m = 0;
        int ans = 0;
        for(int i=idx;i<idx+k && i < n;i++){
            m = max(m, arr[i]);
            ans = max(ans, (i - idx + 1) * m + solution(i+1, n, arr, k, dp));
        }

        return dp[idx] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solution(0, n, arr, k, dp);
    }
};
