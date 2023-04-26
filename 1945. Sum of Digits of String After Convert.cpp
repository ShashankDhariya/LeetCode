class Solution {
public:
    int getLucky(string s, int k) {
        string sum = "";
        for(auto ch: s){
            int num = ch - 'a' + 1;
            if(num > 9){
                sum += (num/10 + '0');
                sum += (num%10 + '0');
            }
            else 
                sum += num + '0';
        }

        int ans = 0;
        while(k--){
            ans = 0;
            for(auto ch: sum)
                ans += ch - '0';

            int temp = ans;
            sum = "";
            while(temp){
                sum += temp%10 + '0';
                temp /= 10;
            }
            reverse(sum.begin(), sum.end());
        }
        return ans;
    }
};
