class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        vector<vector<int>> dp(9, vector<int> (10, 0));
        vector<int>& res = nums;
        for(int i=0;i<9;i++){
            for(auto& r: res) {
                dp[i][r % 10]++;
                r /= 10;
            }
        }

        long long ans = 0;
        int n = nums.size();
        for(auto d: dp){
            for(auto m: d)
                ans += (1ll * m * (n - m));
        }

        return ans / 2;
    }
};
