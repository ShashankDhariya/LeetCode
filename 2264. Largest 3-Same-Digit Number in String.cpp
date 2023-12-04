class Solution {
public:
    string largestGoodInteger(string num) {
        char ans = 0;

        int n = num.length();
        for(int i=1;i<n-1;i++){
            if(num[i-1] == num[i] && num[i] == num[i+1])
                ans = max(ans, num[i]);
        }

        return ans == 0? "": string(3, ans);
    }
};
