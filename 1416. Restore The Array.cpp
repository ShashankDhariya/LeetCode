class Solution {
public:
    #define MOD 1000000007
    int array(int i, int n, string& s, int& k, vector<int>& dp){
        if(i >= n)
            return 1;

        if(s[i] == '0')
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int ans = 0;
        long long num = 0;
        for(int j=i;j<n;j++){
            num = num*10 + (s[j] - '0');
            if(num > k)
                break;
            ans = (ans + array(j+1, n, s, k, dp)) % MOD;
        }
        return dp[i] = ans;
    }

    int numberOfArrays(string s, int k) {
        int n = s.length();

        vector<int> dp(n, -1);
        return array(0, n, s, k, dp);
    }
};
