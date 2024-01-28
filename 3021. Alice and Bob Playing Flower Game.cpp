class Solution {
public:
    long long flowerGame(int n, int m) {
        int oddNum = (n+1)/2;
        int evenNum = n/2;

        long long odd = 1ll * oddNum * (m/2);
        long long even = 1ll * evenNum * ((m+1)/2);

        return odd + even;
    }
};
