class Solution {
public:
    int solution(long long idx, long long jump, bool first, int k, unordered_map<int, unordered_map<int, unordered_map<int, int>>>& dp){
        if((idx - 1) > k)
            return 0;

        if(dp.find(idx) != dp.end() && dp[idx].find(jump) != dp[idx].end() && dp[idx][jump].find(first) != dp[idx][jump].end())
            return dp[idx][jump][first];

        int ans = 0;
        if(idx == k)
            ans++;

        if(first && idx != 0)
            ans += solution(idx - 1, jump, 0, k, dp);

        ans += solution(idx + (1ll << jump), jump+1, 1, k, dp);

        return dp[idx][jump][first] = ans;
    }

    int waysToReachStair(int k) {
        unordered_map<int, unordered_map<int, unordered_map<int, int>>> dp;
        return solution(1, 0, 1, k, dp);
    }
};
