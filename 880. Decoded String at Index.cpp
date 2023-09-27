class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long len = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(isdigit(s[i]))
                len *= (s[i] - '0');
            else 
                len++;
        }

        for(int i=n-1;i>=0;i--){
            if(isdigit(s[i])){
                len /= (s[i] - '0');
                k %= len;
            }
            else {
                if(k == 0 || len == k)
                    return string("") + s[i];
                len--;
            }
        }

        return "";
    }
};
