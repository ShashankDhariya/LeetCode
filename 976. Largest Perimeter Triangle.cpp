class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        for(int i=0;i<nums.size() - 2;i++){
            float p = nums[i] + nums[i+1] + nums[i+2];
            if(p/2 > nums[i] && p/2 > nums[i+1] && p/2 > nums[i+2])
                return nums[i] + nums[i+1] + nums[i+2];
        }
        return 0;
    }
};
