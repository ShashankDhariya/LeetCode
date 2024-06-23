class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        deque<int> minDq;
        deque<int> maxDq;

        int i = 0;
        int n = nums.size();
        for(int j=0;j<n;j++){
            while(!minDq.empty() && minDq.back() > nums[j])
                minDq.pop_back();
            minDq.push_back(nums[j]);

            while(!maxDq.empty() && maxDq.back() < nums[j])
                maxDq.pop_back();
            maxDq.push_back(nums[j]);

            while(maxDq.front() - minDq.front() > limit){
                if(minDq.front() == nums[i])
                    minDq.pop_front();

                if(maxDq.front() == nums[i])
                    maxDq.pop_front();

                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
