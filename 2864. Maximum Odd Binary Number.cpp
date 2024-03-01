class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string str = s;
        int idx = 0;
        int n = s.length();
        for(int i=0;i<n-1;i++){
            if(str[i] == '0')
                continue;

            if(str[n-1] == '1')
                swap(str[idx++], str[i]);
            else 
                swap(str[n-1], str[i]);
        }

        return str;
    }
};
