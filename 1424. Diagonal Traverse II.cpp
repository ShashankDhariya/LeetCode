class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        int n = nums.size();
        map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> res;
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++)
                res[i+j].push({j, nums[i][j]});
        }

        for(auto num: res){
            while(!num.second.empty()){
                ans.push_back(num.second.top().second);
                num.second.pop();
            }   
        }
        return ans;
    }
};
