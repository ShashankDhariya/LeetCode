class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;

        for(int i=0;i<n;i++)
            pq.push(nums[i]);

        int ans;
        while(!pq.empty()){
            if(!k)
                return ans;
            ans = pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};
