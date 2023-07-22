class Solution {
public:
    vector<pair<int, int>> moves = {{-1, 2}, {-2, 1}, {-2,-1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};

    double solution(int i, int j, int n, int k, unordered_map<string, double>& dp){
        if(i < 0 || j < 0 || i >= n || j >= n)
            return 0;

        if(k == 0)
            return 1;

        string key = to_string(i) + '-' + to_string(j) + '-' + to_string(k);
        if(dp.find(key) != dp.end())
            return dp[key];

        double prob = 0;
        for(auto dir: moves)
            prob += solution(i+dir.first, j+dir.second , n, k-1, dp);

        return dp[key] = prob / 8.0;
    }

    double knightProbability(int n, int k, int row, int column) {
        unordered_map<string, double> dp;
        return solution(row, column, n, k, dp);
    }
};
