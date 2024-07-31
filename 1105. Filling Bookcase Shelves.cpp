class Solution {
public:

    int solution(int idx, int& n, vector<vector<int>>& books, int& shelfWidth, vector<int>& dp){
        if(idx == n)
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int ans = 1e9;
        int remW = shelfWidth;
        int maxH = books[idx][1];
        for(int i=idx;i<n;i++){
            remW -= books[i][0];
            if(remW < 0)
                break;

            maxH = max(books[i][1], maxH);
            int res = maxH + solution(i+1, n, books, shelfWidth, dp);
            ans = min(ans, res);
        }

        return dp[idx] = ans;
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n, -1);
        return solution(0, n, books, shelfWidth, dp);
    }
};
