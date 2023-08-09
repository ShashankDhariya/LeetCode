class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.back() - nums.front();

        while(left < right){
            int m = left + (right - left) / 2;

            int ctr = 0;
            for(int i=0;i<n-1;i++){
                if(m >= nums[i+1] - nums[i]){
                    ctr++;
                    i++;
                }
            }
            if(ctr >= p)
                right = m;
            else 
                left = m+1;
        }
        return left;
    }
};
