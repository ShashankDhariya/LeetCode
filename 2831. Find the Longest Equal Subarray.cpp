class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;
        
        int i = 0;
        int j = 0;
        for(int j=0;j<n;j++){
            ans = max(ans, ++mp[nums[j]]);
            if(j - i + 1 - ans > k)
                mp[nums[i++]]--;
        }
        
        return ans;
    }
};
