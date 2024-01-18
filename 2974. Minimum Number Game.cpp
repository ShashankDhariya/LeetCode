class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());
        
        int idx = 1;
        for(int i=0;i<n/2;i++){
            ans.push_back(nums[idx]);
            ans.push_back(nums[idx-1]);
            idx += 2;
        }
        
        return ans;
    }
};
