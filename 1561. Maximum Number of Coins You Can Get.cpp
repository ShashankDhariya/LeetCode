class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans = 0;
        sort(piles.begin(), piles.end());

        int n = piles.size();
        for(int i=n/3;i<n;i+=2)
            ans += piles[i];

        return ans;
    }
};
