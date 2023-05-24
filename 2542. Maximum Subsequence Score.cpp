class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        long long ans = INT_MIN;

        vector<pair<int, int>> res;
        for(int i=0;i<n;i++)
            res.push_back({nums2[i], nums1[i]});
        sort(res.rbegin(), res.rend());

        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<n;i++){            
            if(pq.size() == k){
                sum -= pq.top();
                pq.pop();
            }

            pq.push(res[i].second);
            sum += res[i].second;
            if(pq.size() >= k)
                ans = max(ans, sum*res[i].first);
        }
        return ans;
    }
};
