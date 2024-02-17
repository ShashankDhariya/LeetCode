class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        
        int ans = 0;
        int num = nums[0] + nums[1];
        for(int i=0;i<n-1;i+=2){
            if(nums[i] + nums[i+1] == num)
                ans++;
            else 
                break;
        }
        
        return ans;
    }
};
