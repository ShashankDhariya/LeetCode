class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<int> ans;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            ans.push_back(nums[i][j]);

            int m = nums.size();
            if(j == 0 && i+1 < m)
                q.push({i+1, j});

            int n = nums[i].size();
            if(j+1 < n)
                q.push({i, j+1});
        }

        return ans;
    }
};
