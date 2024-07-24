class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<vector<int>> res;

        int size = nums.size();
        for(int i=0;i<size;i++){
            string str = to_string(nums[i]);
            string newNum = "";

            for(auto ch: str)
                newNum += '0' + mapping[(ch - '0') % 10];

            int n = stoi(newNum);
            res.push_back({n, nums[i], i});
        }

        sort(res.begin(), res.end(), [&](vector<int>& a, vector<int>& b){
            if(a[0] == b[0])
                return a[2] < b[2];
            return a[0] < b[0];
        });

        vector<int> ans;
        for(auto r: res)
            ans.push_back(r[1]);

        return ans;
    }
};
