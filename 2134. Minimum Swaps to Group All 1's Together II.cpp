class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalNum = accumulate(nums.begin(), nums.end(), 0ll);
        nums.insert(nums.end(), nums.begin(), nums.end());

        int ans = 1e9;
        int ctr = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            ctr += (nums[i] - (i - totalNum > -1? nums[i - totalNum]: 0));
            ans = min(ans, totalNum - ctr);
        }

        return ans;
    }
};
