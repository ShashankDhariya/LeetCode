class Solution {
public:
    int mod = 1e9 + 7;

    int revs(int num){
        int revs = 0;
        while(num){
            revs = revs * 10 + (num % 10);
            num /= 10;
        }
        return revs;
    }

    int countNicePairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mp;

        int n = nums.size();
        for(int i=0;i<n;i++){
            int val = nums[i] - revs(nums[i]);
            ans = (ans + mp[val]) % mod;
            mp[val] += 1 % mod;
        }

        return ans;
    }
};
