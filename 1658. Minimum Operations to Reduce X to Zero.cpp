class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(auto num: nums)
            sum += num;

        int target = sum - x;

        int n = nums.size();
        sum = 0;
        int i = 0;
        int j = 0;
        int ans = -1;
        while(j < n){
            sum += nums[j++];
            while(i < j && sum > target)
                sum -= nums[i++];

            if(sum == target)
                ans = max(ans, j - i);
        }

        return ans == -1? -1: (nums.size() - ans);
    }
};
