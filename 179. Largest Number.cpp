class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(), nums.end(), [](int& a, int& b){
            string num1 = to_string(a) + to_string(b);
            string num2 = to_string(b) + to_string(a);
            return num1 > num2;
        });

        for(auto num: nums)
            ans += to_string(num);

        if(ans[0] == '0')
            return "0";

        return ans;
    }
};
