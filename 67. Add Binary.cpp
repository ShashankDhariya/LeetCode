class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int len1 = a.length() - 1;
        int len2 = b.length() - 1;
        int res = 0;
        
        for(int i=0;i<=max(len1, len2) || res;i++){
            int num1 = len1-i > -1 ? a[len1-i] - '0': 0;
            int num2 = len2-i > -1 ? b[len2-i] - '0': 0;

            int num = num1 + num2 + res;
            if(num == 2){
                ans.push_back('0');
                res = 1;
            }
            
            else if(num == 3){
                ans.push_back('1');
                res = 1;
            }

            else {
                ans.push_back(num + '0');
                res = 0;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
