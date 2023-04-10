class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        int j = 0;

        for(int i=0;i<n;i++){
            if(s[i] == 'c' && j > 1 && s[j-1] == 'b' && s[j-2] == 'a')
                j -= 2;
            else 
                s[j++] = s[i];
        }
        return j == 0;
    }
};
