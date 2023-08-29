class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> prefix(n+1, 0);
        vector<int> suffix(n+1, 0);

        for(int i=n-1;i>-1;i--)
            suffix[i] = (customers[i] == 'Y') + suffix[i+1];

        for(int i=1;i<=n;i++)
            prefix[i] = (customers[i-1] == 'N') + prefix[i-1];

        int ans;
        int penalty = INT_MAX;
        for(int i=0;i<=n;i++){
            if(penalty > (suffix[i] + prefix[i])){
                ans = i;
                penalty = suffix[i] + prefix[i];
            }
        }

        return ans;
    }
};
