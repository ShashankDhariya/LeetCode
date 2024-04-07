class Solution {
public:

    bool solution(int idx, int n, int open, string& s, vector<vector<int>>& dp){
        if(idx == n)
            return (open == 0);

        if(dp[idx][open] != -1)
            return dp[idx][open];

        if(s[idx] == '(')
            return solution(idx+1, n, open+1, s, dp);

        if(s[idx] == ')')
            return open == 0? 0: solution(idx+1, n, open-1, s, dp);

        bool a = solution(idx+1, n, open+1, s, dp);
        bool b = open? solution(idx+1, n, open-1, s, dp): 0;
        bool c = solution(idx+1, n, open, s, dp);

        return dp[idx][open] = a || b || c;
    }

    bool checkValidString(string s) {
        int n = s.length();

        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solution(0, n, 0, s, dp);
    }
};
