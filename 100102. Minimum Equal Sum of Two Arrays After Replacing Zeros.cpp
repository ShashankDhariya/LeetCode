class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long z1 = 0;
        long long sum1 = 0;
        for(auto num: nums1){
            sum1 += num;
            if(num == 0)
                z1++;
        }
        
        long long z2 = 0;
        long long sum2 = 0;
        for(auto num: nums2){
            sum2 += num;
            if(num == 0)
                z2++;
        }
        
        if(sum1+z1 > sum2+z2 && z2 == 0)
            return -1;
        
        if(sum1+z1 < sum2+z2 && z1 == 0)
            return -1;
        
        return max(sum1+z1, sum2+z2);
    }
};
