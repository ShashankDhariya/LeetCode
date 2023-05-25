class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0)
            return 1.0;

        if(n >= k-1 + maxPts)
            return 1.0;

        int maxPoints = k-1 + maxPts;
        double windowSum = 1.0;
        
        vector<double> dp(maxPoints+1, 0.0);
        dp[0.0] = 1;

        double ans = 0.0;
        for(int i=1;i<=n;i++){
            dp[i] = windowSum / maxPts;

            if(i < k)
                windowSum += dp[i];
            else 
                ans += dp[i];
            
            if(i >= maxPts)
                windowSum -= dp[i-maxPts];
        }
        return ans;
    }
};
