class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        int ans = INT_MIN;
        sort(satisfaction.rbegin(), satisfaction.rend());

        int preSum = 0;
        int res = 0;
        for(int i=0;i<n;i++){
            preSum += satisfaction[i];
            res += preSum;
            ans = max(ans, res);
        }
        return ans > 0? ans:0;
    }
};
