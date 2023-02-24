class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto num: nums)
            pq.push(num);
        
        nums.clear();
        while(!pq.empty()){
            nums.push_back(pq.top());
            pq.pop();
        }
        return nums;
    }
};
