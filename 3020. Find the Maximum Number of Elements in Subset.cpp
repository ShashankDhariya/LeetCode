class Solution {
public:
    
    long long expo(int num, int pow, long long mod){
        long long ans = 1;
        while(pow){
            if(pow & 1)
                ans = (1ll * ans*num) % mod;
            num = (1ll * num*num) % mod;
            pow /= 2;
        }
        
        return ans;
    }
    
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto num: nums)
            freq[num]++;
        
        int ans = freq[1]%2 == 0? (freq[1] - 1): freq[1];
        
        sort(nums.begin(), nums.end());
        for(auto num : nums){
            if(num == 1 || freq[num] == 0)
                continue;
            
            int res = 0;
            int pow = 0;
            long long ele = num;
            while(freq[ele] > 0){
                res++;
                
                if(freq[ele] == 1)
                    break;
                
                pow += pow == 0? 2: pow;
                ele = expo(num, pow, 1e18);
            }
            freq[num] = 0;
            ans = max(ans, res+res-1);
        }
        
        return ans;
    }
};
