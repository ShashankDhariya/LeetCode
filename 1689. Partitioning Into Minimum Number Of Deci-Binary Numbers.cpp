class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(auto s: n)
            ans = max(ans, s - '0');
        return ans;
    }
};
