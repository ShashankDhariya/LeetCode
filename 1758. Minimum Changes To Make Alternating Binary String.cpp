class Solution {
public:
    int minOperations(string s) {
        int ans1 = 0;
        int ans2 = 0;

        int n = s.length();
        for(int i=1;i<n;i+=2){
            if(s[i-1] == '0')
                ans1++;
            else 
                ans2++;

            if(s[i] == '1')
                ans1++;
            else 
                ans2++;
        }
        
        if(n % 2){
            if(s[n-1] == '0')
                ans1++;
            else 
                ans2++;
        }

        return min(ans1, ans2);
    }
};
