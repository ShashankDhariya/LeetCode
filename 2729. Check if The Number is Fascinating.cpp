class Solution {
public:

    int freq = 0;
    bool check(int n){
        while(n){
            int r = n % 10;
        
            if(r == 0 || ((1 << r) & freq))
                return 0;

            freq |= (1 << r);
            n /= 10;
        }
        return 1;
    }
    bool isFascinating(int n) {
        return (check(n) && check(2*n) && check(3*n));
    }
};
