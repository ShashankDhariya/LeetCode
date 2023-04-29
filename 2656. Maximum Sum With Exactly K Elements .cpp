class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for(auto num: nums)
            pq.push(num);
        
        int ans = 0;
        for(int i=0;i<k;i++){
            int num = pq.top();
            pq.pop();
            pq.push(num+1);
            ans += num;
        }
        return ans;
    }
};
