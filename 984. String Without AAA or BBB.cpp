class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans = "";
        char prev = '1';
        while(a || b){
            if(a > b){
                if(prev == 'a'){
                    ans += 'b';
                    b--;
                    prev = 'b';
                }
                else {
                    if(a > 1){
                        ans += "aa";
                        a -= 2;
                    }
                    else {
                        ans += 'a';
                        a--;
                    }
                    prev = 'a';
                }
            }

            else {
                if(prev == 'b'){
                    ans += 'a';
                    a--;
                    prev = 'a';
                }
                else {
                    if(b > 1){
                        ans += "bb";
                        b -= 2;
                    }
                    else {
                        ans += 'b';
                        b--;
                    }
                    prev = 'b';
                }
            }
        }
        return ans;
    }
};
