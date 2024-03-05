class Solution {
public:
    int minimumLength(string s) {
        int i = 0;
        int j = s.length()-1;
        while(i < j){
            if(s[i] != s[j])
                break;

            while(i < j && s[i] == s[i+1])
                i++;

            while(i <= j && s[j] == s[j-1])
                j--;

            i++;
            j--;
        }

        return max(0, j - i + 1);
    }
};
