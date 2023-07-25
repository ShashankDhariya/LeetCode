class Solution {
public:
    #define ll long long
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        int i = 0;
        int j = 0;

        ll prod = 1;
        while(i < n && j < n){
            prod *= nums[j];
            while(i < n && prod >= k)
                prod /= nums[i++];

            if(prod < k)
                ans += (j - i + 1);
            j++;
        }
        return ans;
    }
};
