class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int ans = 0;
        int times = 0;

        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i - k > - 1 && nums[i - k] > 1)
                times--;

            if((times % 2 && nums[i]) || (times % 2 == 0 && !nums[i])){
                if(i + k > n)
                    return -1;
                    
                nums[i] += 2;
                ans++;
                times++;
            }
        }

        return ans;
    }
};
