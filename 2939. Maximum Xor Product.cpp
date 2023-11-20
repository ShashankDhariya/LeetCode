class Solution {
public:
    int mod = 1e9 + 7;
    int maximumXorProduct(long long a, long long b, int n) {
        if(n == 0)
            return ((a % mod) * (b % mod)) % mod;

        for(long long res = 1LL << n-1; res > 0; res >>= 1){
            if((min(a, b) & res) == 0){
                a ^= res;
                b ^= res;
            }
        }

        return ((a % mod) * (b % mod)) % mod;
    }
};
