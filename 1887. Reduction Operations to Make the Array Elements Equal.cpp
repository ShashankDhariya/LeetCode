class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());

        int less = 0;
        int prev = nums[0];
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] != prev){
                prev = nums[i];
                less++;
            }

            ans += less;
        }

        return ans;
    }
};
