#define ll long long
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        
        int n = nums.size();
        for(int i=0;i<n;i++)
            pq.push(nums[i]);
        
        int ans = 0;
        while(pq.size() > 1 && pq.top() < k){
            ll x = pq.top();
            pq.pop();
            ll y = pq.top();
            pq.pop();
            
            ll a = min(x, y) * 2 + max(x, y);
            pq.push(a);
        
            ans++;
        }
        
        return ans;
    }
};
