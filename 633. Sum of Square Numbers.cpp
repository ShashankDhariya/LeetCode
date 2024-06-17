#define ll long long
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(ll i=0;i*i<=c;i++){
            ll a = i*i;
            ll rem = c-a;
            ll num = sqrt(rem);
            if(num * num != rem)
                continue;

            return 1;
        }

        return 0;
    }
};
