class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int ,int> m1;
        priority_queue<pair<int, int>> pq;

        for(int i=0;i<n;i++)
            m1[nums[i]]++;

        for(auto num: m1)
            pq.push({num.second, num.first});

        vector<int> ans;
        while(!pq.empty()){
            if(!k)
                return ans;
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};
