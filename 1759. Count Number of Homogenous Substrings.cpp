class Solution {
public:
    int mod = 1e9+7;
    int countHomogenous(string s) {
        int n = s.length();

        int ans = 0;
        for(int i=0;i<n;i){
            int j = i;
            int ctr = 0;
            while(j < n && s[i] == s[j]){
                ctr++; 
                j++;
                ans = (ans + ctr) % mod;
            }
            i = j;
        }

        return ans;
    }
};
