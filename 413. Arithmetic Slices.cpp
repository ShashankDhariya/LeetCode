class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return 0;

        int ans = 0;
        int res = 0;
        int prevDiff = nums[1] - nums[0];

        for(int i=2;i<n;i++){
            int diff = nums[i] - nums[i-1];

            if(diff == prevDiff)
                res++;

            else {
                prevDiff = diff;
                res = 0;
            }
            ans += res;
        }
        return ans;
    }
};
