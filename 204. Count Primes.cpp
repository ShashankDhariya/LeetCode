class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)   return 0;
        vector<int> isPrime(n, 1);

        for(int i=2;i*i<n;i++){
            if(isPrime[i]){
                for(int j=2*i;j<n;j+=i)
                    isPrime[j] = 0;
            }
        }

        int ans = 0;
        for(int i=2;i<n;i++)
            if(isPrime[i])
                ans++;
        return ans;
    }
};
