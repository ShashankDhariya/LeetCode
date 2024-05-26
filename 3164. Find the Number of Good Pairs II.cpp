class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        map<int, int> freq;
        for(auto num: nums2)
            freq[num * k]++;
        
        long long ans = 0;
        for(auto num: nums1){
            for(int i=1;i*i<=num;i++){
                if(num % i == 0){
                    ans += freq[i];
                    if(i*i != num)
                        ans += freq[num/i];
                }
            }
        }
        
        return ans;
    }
};
