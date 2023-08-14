class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        priority_queue<int> pq;
        for(auto num: nums)
            pq.push(num);
        
        int n = nums.size();
        for(int i=1;i<n;i+=2){
            nums[i] = pq.top();
            pq.pop();
        }

        for(int i=0;i<n;i+=2){
            nums[i] = pq.top();
            pq.pop();
        }
    }
};
