class Solution {
public:
    int mod = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> bits(32, 0);

        int n = nums.size();
        for(int i=0;i<32;i++){
            for(int j=0;j<n;j++){
                if(nums[j] & 1)
                    bits[i]++;
                nums[j] >>= 1;
            }
        }

        int ans = 0;
        for(int j=0;j<k;j++){
            int num = 0;
            for(int i=0;i<32;i++){
                if(bits[i]){
                    bits[i]--;
                    num |= (1 << i);
                }
            }
            ans = (ans + (1LL * num * num) % mod) % mod;
        }

        return ans;
    }
};
