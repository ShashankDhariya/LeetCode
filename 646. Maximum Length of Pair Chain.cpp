// TC: O(nlogn + n): Greedy
// SC: O(1)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });

        int n = pairs.size();
        int ans = 0;
        int prev = -1001;
        for(int i=0;i<n;i++){
            if(prev < pairs[i][0]){
                prev = pairs[i][1];
                ans++;
            }
        }

        return ans;
    }
};

// OR
// TC: O(nlogn + nlogn): Trying all possible ways
// SC: O(n)
class Solution {
public:
    int solution(int idx, int n, vector<int>& res, vector<vector<int>>& pairs, vector<int>& dp) {
        if(idx == n)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];

        int ind = upper_bound(res.begin(), res.end(), pairs[idx][1]) - res.begin();
        int pick = 1 + solution(ind, n, res, pairs, dp);
        int notPick = solution(idx+1, n, res, pairs, dp);

        return dp[idx] = max(pick, notPick);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());

        int n = pairs.size();
        vector<int> res;
        for(auto pair: pairs)
            res.push_back(pair[0]);

        vector<int> dp(n, -1);
        return solution(0, n, res, pairs, dp);
    }
};
