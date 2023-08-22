class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber){
            int chIdx = --columnNumber % 26;
            ans += ('A' + chIdx);
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
