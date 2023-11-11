class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long ans = 0;
        int m = values.size();
        int n = values[0].size();
        
        vector<int> nums;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                nums.push_back(values[i][j]);
            }
        }
        
        sort(nums.begin(), nums.end());
        long long day = 1;
        for(auto num: nums){
            ans += (num*day);
            day++;
        }
        
        return ans;
    }
};
