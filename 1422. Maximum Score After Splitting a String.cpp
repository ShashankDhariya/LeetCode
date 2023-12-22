class Solution {
public:
    int maxScore(string s) {
        int n = s.length();

        int one = 0;
        for(auto ch: s)
            one += ch == '1'? 1: 0;

        int ans = 0;
        int zero = 0;
        for(int i=0;i<n-1;i++){
            if(s[i] == '0')
                zero++;
            else 
                one--;
            
            if(one || zero)
                ans = max(ans, zero + one);
        }

        return ans;
    }
};
