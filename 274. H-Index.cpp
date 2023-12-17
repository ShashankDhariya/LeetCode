class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        sort(citations.begin(), citations.end());

        int n = citations.size();
        for(int i=n-1;i>-1;i--){
            if(n - i <= citations[i])
                ans = n-i;
        }

        return ans;
    }
};
