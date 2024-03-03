class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] >= k)
                return i;
        }
        
        return n;
    }
};
