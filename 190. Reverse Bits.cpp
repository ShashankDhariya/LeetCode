class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int i = 31;
        while(n){
            if(n & 1)
                ans |= (1 << i);
            i--;
            n >>= 1;
        }
        return ans;
    }
};
