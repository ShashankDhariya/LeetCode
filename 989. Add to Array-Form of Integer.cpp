class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int i = num.size() - 1;
        int carry = 0;

        while(k || i > -1 || carry){
            int num1 = k? k%10 : 0;
            int num2 = i > -1? num[i--]: 0;

            int sum = num1 + num2 + carry;
            if(sum > 9) carry = 1;
            else carry = 0;

            ans.push_back(sum%10);
            k /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
