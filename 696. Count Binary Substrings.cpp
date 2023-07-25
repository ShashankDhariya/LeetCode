class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();

        int ans = 0;
        int one = 0;
        int two = 0;

        int i = 0;
        int j = 0;
        while(i < n && j < n){
            char num = s[i];
            while(s[j] == num){
                if(s[j] == '1') one++;
                else two++;
                j++;
            }
            i = j;
            if(one > 0 && two > 0){
                ans += min(one, two);
                if(num == '1')
                    two = 0;
                else
                    one = 0;
            }
        }
        return ans;
    }
};
