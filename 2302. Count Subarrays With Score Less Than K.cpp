class Solution {
public:
    #define ll long long 
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        ll ans = 0;
        ll sum = 0;
        
        int i = 0;
        int j = 0;

        while(i < n && j < n){
            sum += nums[j];
            while(i < n && sum*(j-i+1) >= k)
                sum -= nums[i++];

            ans += (j - i + 1);
            j++;
        }

        return ans;
    }
};
