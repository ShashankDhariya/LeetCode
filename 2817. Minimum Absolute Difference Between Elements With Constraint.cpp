class Solution {
public:
    #define ll long long
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        set<ll> s;
        
        ll ans = INT_MAX;
        for(int i=n-x-1;i>-1;i--){
            s.insert(nums[i+x]);
            
            auto idx = lower_bound(s.begin(), s.end(), nums[i]);
            if(idx != s.end())
                ans = min(ans, abs(nums[i] - *idx));
            if(idx != s.begin()){
                idx--;
                ans = min(ans, abs(nums[i] - *idx));
            }
        }
        return ans;
    }
};
