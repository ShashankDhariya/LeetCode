class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        long long left = 0;
        long long right = 0;
        for(auto num: nums)
            right += num;

        vector<int> ans;
        for(int i=0;i<n;i++){
            left += nums[i];
            ans.push_back(((i+1)*nums[i] - left) + ((right - left) - (n-i-1)*nums[i]));
        }

        return ans;
    }
};
