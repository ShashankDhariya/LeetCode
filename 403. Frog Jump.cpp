class Solution {
public:

    bool jumps(int i, int jump, vector<int>& stones, unordered_map<string, bool>& dp){
        if(i == stones.size() - 1)
            return 1;

        string str = to_string(i) + '-' + to_string(jump);
        if(dp.find(str) != dp.end())
            return dp[str];

        for(int j=i+1;j<stones.size();j++){
            if(stones[i] + jump - 1 == stones[j])
                if(jumps(j, jump-1, stones, dp))    return 1;

            if(stones[i] + jump == stones[j])
                if(jumps(j, jump, stones, dp))  return 1;

            if(stones[i] + jump + 1 == stones[j])
                if(jumps(j, jump+1, stones, dp))    return 1;
        }

        return dp[str] = 0;
    }

    bool canCross(vector<int>& stones) {
        unordered_map<string, bool> dp;
        return jumps(0, 0, stones, dp);
    }
};
