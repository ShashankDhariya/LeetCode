class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;

        int n = nums.size();
        for(int i=n-2;i>=0;i--){
            int num = ceil(nums[i] / (double)nums[i+1]);
            
            nums[i] /= num;
            ans += (num-1);
        }

        return ans;
    }
};
