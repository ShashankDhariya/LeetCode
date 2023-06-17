class Solution {
public:
    int solution(int ind, int prev, vector<int>& arr1, int n, vector<int>& arr2, map<pair<int, int>, int>& dp){
        if(dp.find({ind, prev}) != dp.end())
            return dp[{ind, prev}];

        if(ind == n)
            return 0;
        
        int ans = INT_MAX/2;
        int i = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();

        if(arr1[ind] > prev) 
            ans = min(ans, solution(ind+1, arr1[ind], arr1, n, arr2, dp));
        if(i < arr2.size())
            ans = min(ans, solution(ind+1, arr2[i], arr1, n, arr2, dp) + 1);
        return dp[{ind, prev}] = ans;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        map<pair<int, int>, int> dp;
        int ans = solution(0, INT_MIN, arr1, arr1.size(), arr2, dp);
        return ans >= INT_MAX/2? -1: ans;
    }
};
