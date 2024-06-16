class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int size = nums.size();

        int ans = 0;
        int idx = 0;
        long long sum = 1;
        while(sum <= n){
            if(idx < size && nums[idx] <= sum)
                sum += nums[idx++];

            else{
                sum += sum;
                ans++;
            }
        }

        return ans;
    }
};
