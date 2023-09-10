class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
             
        vector<vector<int>> res;
        res.push_back(nums[0]);
             
        for(int i=1;i<nums.size();i++){
            auto n = res.back();
            if(n[1] >= nums[i][0]){
                res.pop_back();
                res.push_back({min(n[0], nums[i][0]), max(n[1], nums[i][1])});
            }
            else
                res.push_back(nums[i]);
        }
            
        for(auto a: res)
            ans += (a[1] - a[0] + 1);
        
        return ans;
    }
};
