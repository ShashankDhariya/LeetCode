class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        for(int a=0;a<n;a++){
            if(nums[a] == 1)    i = a;
            if(nums[a] == n)    j = a;
        }    

        int ans = i + n - j - 1;
        if(i < j)
            return ans;
        return ans - 1;
    }
};
