class Solution {
public:

    #define ll long long
    long long minIncrementOperations(vector<int>& nums, int k) {
        ll ans = 0;
        ll dp1 = 0;
        ll dp2 = 0;
        ll dp3 = 0;

        for(auto num: nums){
            ans = min({dp1, dp2, dp3}) + max(k-num, 0);
            dp1 = dp2;
            dp2 = dp3;
            dp3 = ans;
        }

        return min({dp1, dp2, dp3});
    }
};
