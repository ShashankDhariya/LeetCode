class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        
        int a = 0;
        while(1){
            int bits = 0;
            bool b = 1;
            for(int i=0;i<n;i++){
                if(nums[i] != 0)
                    b = 0;
                if(nums[i] & 1)
                    bits++;
                nums[i] >>= 1;
            }
            if(bits >= k){
                ans += pow(2, a);
                cout<<a<<" ";
            }
            if(b)
                break;
            a++;
        }
        
        return ans;
    }
};
