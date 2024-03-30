class Solution {
public:
    int sumOfPowers(vector<int>& nums, int k) {
        int ans = 1e5;
        
        int n = nums.size();
        
        vector<vector<int>> res(n, vector<int> (31, 0));
        for(int i=0;i<n;i++){
            int curr = nums[i];
            for(int j=0;j<31;j++){
                if(curr & 1)
                    res[i][j]++;
                curr >>= 1;
            }
        }
        
        for(int i=0;i<31;i++){
            
        }
    }
};
