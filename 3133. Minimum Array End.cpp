class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        long long num = n;

        num--;
        for(int i=0;i<62;i++){
            long long checker = (1ll << i);
            if((x & checker) == 0){
                if(num & 1)
                    ans |= (1ll << i);
                
                num >>= 1;
            }
        }

        return ans;
    }
};
