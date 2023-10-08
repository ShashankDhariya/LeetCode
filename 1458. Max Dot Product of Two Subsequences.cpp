class Solution {
public:

    int solution(int i, int j, int m, int n, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        if(i == m || j == n)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int p1 = (nums1[i] * nums2[j]) + solution(i+1, j+1, m, n, nums1, nums2, dp);
        int p2 = solution(i+1, j, m, n, nums1, nums2, dp);
        int p3 = solution(i, j+1, m, n, nums1, nums2, dp);
        int p4 = solution(i+1, j+1, m, n, nums1, nums2, dp);

        return dp[i][j] = max({p1, p2, p3, p4});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        int ans = solution(0, 0, m, n, nums1, nums2, dp);

        if(ans == 0){
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            return max(nums1[0] * nums2[n-1], nums1[m-1] * nums2[0]);
        }
        return ans;
    }
};
