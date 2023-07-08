class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int ans = -1;
        for(int i=0;i<n;i++){
            int x = nums[i];
            int a = i % 2;
            int res = 0;
            for(int j=i;j<n;j++){
                if(j % 2 == a) {
                    if(nums[j] == x)
                        res++;
                    else 
                        break;
                }
                else{
                    if(nums[j] == x+1)
                        res++;
                    else 
                        break;
                }
                    
            }
            ans = max(ans, res);
        }
        return ans < 2? -1: ans;
    }
};
