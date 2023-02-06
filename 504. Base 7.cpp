class Solution {
public:
    string convertToBase7(int num) {
        if(!num)
            return "0";

        string ans = num < 0? "-":""; 
        num = num < 0? -num: num;

        while(num){
            ans.push_back(num%7 + '0');
            num /= 7;
        }
        if(ans[0] == '-')
            reverse(ans.begin()+1, ans.end());
        else 
            reverse(ans.begin(), ans.end());
        return ans;
    }
};
