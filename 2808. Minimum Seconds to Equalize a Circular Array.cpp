class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;

        int n = nums.size();
        for(int i=0;i<n;i++)
            pos[nums[i]].push_back(i);

        int ans = INT_MAX;
        for(auto& [key, p]: pos){
            p.push_back(p[0] + n);
            int sec = 0;
            for(int i=0;i<p.size()-1;i++)
                sec = max(sec, p[i+1] - p[i]);

            ans = min(ans, sec/2);
        }
        return ans;
    }
};
