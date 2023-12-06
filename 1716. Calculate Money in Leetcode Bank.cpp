class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        
        int full = n / 7;
        ans += (full * (56 + (full - 1) * 7)) / 2;

        int rem = n % 7;
        ans += (rem * (2*(full+1) + (rem - 1))) / 2;

        return ans;
    }
};
