class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        if(indexDifference >= n)
            return {-1, -1};
        
        int mini = 0;
        int maxi = 0;
        for(int i=indexDifference;i<n;i++){
            if(nums[mini] > nums[i-indexDifference])
                mini = i - indexDifference;
            if(abs(nums[i] - nums[mini]) >= valueDifference)
                return {mini, i};
            
            if(nums[maxi] < nums[i-indexDifference])
                maxi = i - indexDifference;
            if(abs(nums[i] - nums[maxi]) >= valueDifference)
                return {maxi, i};
        }
        
        return {-1, -1};
    }
};
