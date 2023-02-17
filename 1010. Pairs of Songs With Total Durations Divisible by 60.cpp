class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        long long ans = 0;
        vector<long long> rem(60, 0);

        for(int i=0;i<n;i++)
            rem[time[i] % 60]++;

        for(int i=1;i<30;i++)
            ans += rem[i] * rem[60 - i];
        
        ans += rem[0] * (rem[0] - 1)/2;
        ans += rem[30] * (rem[30] - 1)/2;
        return ans;
    }
};
