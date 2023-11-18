class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ans = 1;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = n-2;
        int j = n-1;
        while(i > -1){
            while(j > 0 && nums[j] - nums[i] > k){
                k += ((nums[j] - nums[j-1]) * (j - i - 1));
                j--;
            }

            k -= (nums[j] - nums[i]);
            i--;
            ans = max(ans, j-i);
        }

        return ans;
    }
};
