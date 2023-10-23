class Solution {
public:
    bool isPowerOfFour(int n) {
        bool b = 0;
        for(int i=0;i<=31;i++){
            if(n & 1 == 1){
                if(i % 2 == 1)
                    return 0;
                if(b)
                    return 0;
                b = 1;
            }
            n >>= 1;
        }

        return b;
    }
};
