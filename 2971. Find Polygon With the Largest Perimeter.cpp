class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        long long ans = -1;
        int n = nums.size();
        long long sum = 0;
        for(int i=0;i<n-1;i++){
            sum += nums[i];
            if(i > 0 && sum > nums[i+1])
                ans = sum+nums[i+1];
        }
        
        return ans;
    }
};
