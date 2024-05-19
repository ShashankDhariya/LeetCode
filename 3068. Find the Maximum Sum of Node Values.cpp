class Solution {
public:
    #define ll long long
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll ans = accumulate(nums.begin(), nums.end(), 0ll);
        ll minVal = 1e9;
        int ctrPos = 0;
        for(auto num: nums){
            ll diff = (num^k) - num;

            if(diff > 0){
                ans += diff;
                ctrPos++;
            }

            minVal = min(minVal, abs(diff));
        }

        if(ctrPos % 2 == 1)
            ans -= minVal;

        return ans;
    }
};
