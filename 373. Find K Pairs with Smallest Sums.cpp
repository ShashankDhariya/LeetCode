class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;

        for(int i=0;i<n1 && i<k;i++)
            pq.push({nums1[i]+nums2[0], {i, 0}});

        vector<vector<int>> ans;
        while(!pq.empty() && k--){
            auto curr = pq.top();
            int sum = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            ans.push_back({nums1[i], nums2[j]});
            pq.pop();
            if(j+1 == n2)
                continue;
            pq.push({nums1[i]+nums2[j+1], {i,j+1}});
        }
        return ans;
    }
};
