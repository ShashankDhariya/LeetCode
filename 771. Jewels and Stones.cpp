class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;

        for(auto j:jewels)
            ans += count(stones.begin(), stones.end(), j);
        return ans;
    }
};
