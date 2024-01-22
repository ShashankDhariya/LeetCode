class Solution {
public:
    
    bool isSorted(vector<int>& nums){
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i] > nums[i+1])
                return 0;
        }
        
        return 1;
    }
    
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        
        int idx = 0;
        while(idx < n){
            if(*min_element(nums.begin()+idx, nums.end()) == nums[idx]){
                idx++;
                continue;
            }
            
            bool b = 1;
            for(int i=idx;i<n-1;i++){
                if(nums[i] > nums[i+1] && __builtin_popcount(nums[i]) == __builtin_popcount(nums[i+1])){
                    b = 0;
                    swap(nums[i], nums[i+1]);
                }
            }
                                           
            if(b)   return 0;
        }
                                           
        return isSorted(nums);
    }
};
