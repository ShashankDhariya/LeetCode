class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        int dup = -1;
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += abs(nums[i]);
            if(nums[abs(nums[i]) - 1] < 0)
                dup = abs(nums[i]);

            else 
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }

        int np = abs((n*(n+1) / 2) - (sum - dup));

        return {dup, np};
    }
};
