class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if(x == 1 || n == 0)
            return 1;

        long long rp = n;
        if(n < 0)
            rp = -1 * (long)n;

        while(rp){
            if(rp % 2 == 0){
                x *= x;
                rp /= 2;
            }
            else {
                ans *= x;
                rp--;
            }
        }
        if(n < 0)
            return 1 / ans;
        return ans;
    }
};
