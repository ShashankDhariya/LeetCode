class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        map<int, int> mp;
        int i = 0;
        int j = 0;
        while(j < n){
            mp[nums[j]]++;
            while(mp.size() > 1 && mp.rbegin()->first - mp.begin()->first > 2){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
};
