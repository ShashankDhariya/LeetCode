class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int idx = -1;
        for(int i=0;i<n;i++){
            if(nums[i] < mini){
                mini = nums[i];
                idx = i;
            }
        }
        
        int j = idx;
        for(int i=0;i<n-1;i++){
            if(nums[j % n] > nums[(j + 1) % n])
                return -1;
            j++;
        }
        
        if(idx == 0)
            return 0;
        
        return n - idx;
    }
};
