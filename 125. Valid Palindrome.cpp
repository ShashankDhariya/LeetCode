class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(auto ch: s){
            if(ch >= 65 && ch <= 90)
                str += (ch + 32);
            else if(ch >= 97 && ch <= 122)
                str += ch;
            else if(ch >= '0' && ch <= '9')
                str += ch;
        }

        int i = 0;
        int j = str.length() - 1;
        while(i < j){
            if(str[i++] != str[j--])
                return 0;
        }
        return 1;
    }
};
