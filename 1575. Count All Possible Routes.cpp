class Solution {
public:
    int mod = 1e9+7;
    int solution(int ind, int finish, vector<int>& locations, int fuel, vector<vector<int>>& dp) {
        if(fuel < 0)
            return 0;

        if(dp[ind][fuel] != -1)
            return dp[ind][fuel];

        int ans = 0;
        if(ind == finish)
            ans++;

        for(int i=0;i<locations.size();i++){
            if(i == ind)
                continue;
            ans += solution(i, finish, locations, fuel - abs(locations[i] - locations[ind]), dp);
            ans %= mod;
        }
        return dp[ind][fuel] = ans % mod;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int> (fuel+1, -1));
        return solution(start, finish, locations, fuel, dp);
    }
};
