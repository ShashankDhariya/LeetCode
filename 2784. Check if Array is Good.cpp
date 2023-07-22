class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        if(n == 1)
            return 0;
        
        for(int i=0;i<n-1;i++){
            if(i == n-2){
                if(nums[i] != i+1 || nums[i+1] != i+1)
                    return 0;
            }
            else if(nums[i] != i+1)    
                return 0;
        }
        return 1;
    }
};
