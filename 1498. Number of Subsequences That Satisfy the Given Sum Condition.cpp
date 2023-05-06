class Solution {
public:
    #define MOD 1000000007
    long long power(long long a, long long n, long long m){
        long long res = 1;
        while(n){
            if(n % 2 == 1){
                res = (res * a) % m;
                n--;
            }
            else {
                a = (a * a) % m;
                n /= 2;
            }
        }
        return res;
    }

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = n-1;

        long long ans = 0;
        while(i <= j){
            if(nums[i] + nums[j] > target)
                j--;

            else {
                int res = (int)power(2, j-i, MOD);
                ans = (ans + res) % MOD;
                i++;
            }
        }
        return ans;
    }
};
