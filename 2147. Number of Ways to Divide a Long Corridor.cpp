class Solution {
public:
    int mod = 1e9+7;
    int numberOfWays(string corridor) {
        int ans = 1;

        bool canSplit = 0;
        int p = 1;
        int s = 0;
        int n = corridor.length();
        for(auto it: corridor){
            if(it == 'S'){
                ans = (1LL * ans * p) % mod;
                p = 1;
                s? s--, canSplit = 1: s++;
            }
            else if(s == 0 && canSplit)
                p++;
        }

        return canSplit && !s? ans: 0;
    }
};
