class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int, int>> res;

        for(int i=0;i<n;i++)
            res.push_back({nums[i], cost[i]});

        sort(res.begin(), res.end());

        long long sum = 0;
        for(auto num: res)
            sum += num.second;

        long long total = 0;
        int median = 0;
        int i = 0;
        while(total < (sum+1)/2 && i < n){
            total += res[i].second;
            median = res[i].first;
            i++;
        }

        long long ans = 0;
        for(int i=0;i<n;i++)
            ans += (abs(nums[i] - median) * (long long)cost[i]);

        return ans;
    }
};
