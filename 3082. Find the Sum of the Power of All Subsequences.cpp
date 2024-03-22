#define ll long long
class Solution {
public:
    int mod = 1e9 + 7;
    ll expo(ll a, ll b){
        ll ans = 1;
        while(b){
            if(b % 2 == 1)  ans = (ans*a) % mod;
            a = (a*a) % mod;
            b /= 2;
        }

        return ans;
    }

    int subSeq(int i, int n, int size, vector<int>& nums, int k, vector<vector<vector<int>>>& dp){
        if(k == 0)
            return expo(2, n - size) % mod;

        if(i == n || k < 0)
            return 0;

        if(dp[i][size][k] != -1)
            return dp[i][size][k];
        
        int taken = subSeq(i+1, n, size+1, nums, k-nums[i], dp) % mod;
        int notTaken = subSeq(i+1, n, size, nums, k, dp) % mod;

        return dp[i][size][k] = (1ll*taken + notTaken) % mod;
    }

    int sumOfPower(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (n+1, vector<int> (101, -1)));
        return subSeq(0, n, 0, nums, k, dp);
    }
};
