class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;

        int sum = 0;
        unordered_map<int, int> mp;
        int n = nums.size();
        mp[0] = 0;
        for(int i=0;i<n;i++){
            sum += (nums[i])? 1: -1;

            if(mp.find(sum) != mp.end())
                ans = max(ans, i - mp[sum] + 1);

            else 
                mp[sum] = i+1;
        }

        return ans;
    }
};
