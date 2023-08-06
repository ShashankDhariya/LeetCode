class Solution {
public:
    #define ll long long
    int mod = 1e9+7;
    ll dp[101][101];

    ll songs(int i, int used, int n, int goal, int k) {
        if(i == goal)
            return used == n;

        if(dp[i][used] != -1)
            return dp[i][used];

        ll usedPlay = (songs(i+1, used, n, goal, k)) * max(0, used-k) % mod;
        ll newPlay = (songs(i+1, used+1, n, goal, k)) * (n - used) % mod;

        ll total = (usedPlay + newPlay) % mod;

        return dp[i][used] = total % mod;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp, -1, sizeof(dp));
        return songs(0, 0, n, goal, k);
    }
};
