class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        sort(happiness.rbegin(), happiness.rend());

        int ctr = 0;
        for(int i=0;i<k;i++)
            ans += max(0, happiness[i] - ctr++);

        return ans;
    }
};
