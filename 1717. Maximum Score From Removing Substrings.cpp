class Solution {
public:

    int solution(string& s, string& str, int& x){
        int res = 0;

        int i = 0;
        int n = s.length();
        for(int j=0;j<n;j++){
            s[i++] = s[j];

            if(i > 1 && s[i-2] == str[0] && s[i-1] == str[1]){
                i -= 2;
                res += x;
            }
        }

        s = s.substr(0, i);
        return res;
    }

    int maximumGain(string s, int x, int y) {
        string str1 = "ab";
        string str2 = "ba";

        if(x < y) {
            swap(x, y);
            swap(str1, str2);
        }

        return solution(s, str1, x) + solution(s, str2, y);
    }
};
