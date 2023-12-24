class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                
                bool b = 1;
                int prev = -1;
                for(int k=0;k<n;k++){
                    if(k >= i && k <= j)
                        continue;
                    
                    if(prev == -1)
                        prev = nums[k];
                    
                    else{    
                        if(nums[k] <= prev){
                            b = 0;
                            break;
                        }
                        
                        else 
                            prev = nums[k];
                    }
                }
                
                if(b)
                    ans++;
            }
        }
        
        return ans;
    }
};
