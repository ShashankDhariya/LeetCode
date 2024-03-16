class Solution {
public:
    
    int encrypt(int num){
        int n = num;
        int maxD = 0;
        while(n){
            maxD = max(maxD, n % 10);
            n /= 10;
        }
        
        int ans = 0;
        n = num;
        while(n){
            ans = ans*10 + maxD;
            n /= 10;
        }
        
        return ans;
    }
    
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for(auto num: nums)
            sum += encrypt(num);
        
        return sum;
    }
};
