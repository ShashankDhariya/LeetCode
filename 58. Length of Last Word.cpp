class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length() - 1;
        while(n > -1 && s[n] == ' ')
            n--;

        int last = n;
        while(last > -1 && s[last] != ' ')
            last--;
        
        return n - last;
    }
};
