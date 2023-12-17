class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        for(int i=1;i<n-1;i+=3){
            if(nums[i+1] - nums[i-1] <= k)
                ans.push_back({nums[i-1], nums[i], nums[i+1]});
            
            else 
                return {};
        }
        
        return ans;
    }
};
