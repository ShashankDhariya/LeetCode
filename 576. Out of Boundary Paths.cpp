class Solution {
public:
    int mod = 1e9+7;
    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int solution(int i, int j, int m, int n, int maxMove, unordered_map<string, int>& dp){
        if(i < 0 || i == m || j < 0 || j == n)
            return 1;
            
        if(maxMove == 0)
            return 0;

        string str = to_string(i) + " " + to_string(j) + " " + to_string(maxMove);
        if(dp.find(str) != dp.end())
            return dp[str];

        long long res = 0;
        for(auto d: dir)
            res += solution(i+d.first, j+d.second, m, n, maxMove-1, dp) % mod;

        return dp[str] = res % mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        unordered_map<string, int> dp;
        return solution(startRow, startColumn, m, n, maxMove, dp);
    }
};
