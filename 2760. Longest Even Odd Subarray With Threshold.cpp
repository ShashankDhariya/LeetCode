class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int ans = 0;
        int res = 0;
        int s = -1;
        bool prev = false;
        
        for(int i=0;i<n;i++){
            if(nums[i] > threshold){
                res = 0;
                s = -1;
            }
            
            else if(s != -1){
                if(prev && nums[i] % 2 != 0){
                    prev = 0;
                    res++;
                }
                else if(!prev && nums[i] % 2 == 0){
                    prev = 1;
                    res++;
                }
                else {
                    res = 0;
                    s = -1;
                }
            }
            if(nums[i] > threshold){
                res = 0;
                s = -1;
            }
            
            else if(s == -1 && nums[i] % 2 == 0){
                res++;
                s = i;
                prev = 1;
            }
            ans = max(ans, res);
        }
        return ans;
    }
};
