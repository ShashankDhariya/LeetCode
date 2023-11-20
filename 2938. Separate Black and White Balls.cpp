class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        
        int idx = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i] == '0')
                ans += (i - idx++);
        }
        
        return ans;
    }
};
