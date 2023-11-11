class Solution {
public:
    #define ll long long
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        
        for(int i=0;i<=limit;i++){
            ll rem = (n - i);
            if(rem < 0)
                break;
            
            else if(rem == 0)
                ans += 1;
            
            else if(rem <= (2*(ll)limit)){
                if(rem <= limit)
                    ans += (rem + 1);
                else 
                    ans += ((1LL * 2 * limit) - rem + 1);
            }
        }
        
        return ans;
    }
};
