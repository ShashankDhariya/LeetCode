class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one = 0;
        for(auto ch: s){
            if(ch == '1')
                one++;
        }
        
        int n = s.length()-1;
        s[n] = '1';
        one--;
        
        for(int i=0;i<n;i++){
            if(one-- > 0)
                s[i] = '1';
            else 
                s[i] = '0';
        }
    
        return s;
    }
};
