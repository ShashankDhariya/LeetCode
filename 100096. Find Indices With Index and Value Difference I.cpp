class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+indexDifference;j<n;j++){
                if(valueDifference <= abs(nums[i] - nums[j]))
                    return {i, j};
            }
        }
        return {-1, -1};
    }
};
