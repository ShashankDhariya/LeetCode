class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip = 0;
        while(a > 0 || b > 0 || c > 0){
            int ba = a & 1;
            int bb = b & 1;
            int ca = c & 1;

            if(ca == 0)
                flip += (ba + bb);

            else if(!(ba | bb)) flip++;

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return flip;
    }
};
