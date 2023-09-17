class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            int num = i;
            int bits = 0;
            while(num){
                bits += (num & 1);
                num >>= 1;
            }
            if(bits == k)
                sum += nums[i];
        }
        
        return sum;
    }
};
