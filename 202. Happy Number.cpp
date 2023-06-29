class Solution {
public:
    bool isHappy(int n) {
        if(n == 1 || n == 7)
            return 1;

        if(n / 10 == 0)
            return 0;

        int sum = 0;
        while(n){
            int r = n % 10;
            sum += (r*r);
            n /= 10;
        }
        return isHappy(sum);
    }
};
