class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;

        for(auto c: columnTitle){
            int a = c - 'A' + 1;
            ans = ans*26 + a;
        }
        return ans;
    }
};

OR

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
      
        int n = columnTitle.length();
        for(int i=0;i<n;i++)
            ans += (pow(26, n-1-i) * (columnTitle[i] - 'A' + 1)) ;
        return ans;
    }
};
