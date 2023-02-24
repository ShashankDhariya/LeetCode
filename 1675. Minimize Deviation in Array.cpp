class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;

        int minVal = INT_MAX;
        for(auto num: nums){
            if(num % 2 != 0)
                num *= 2;
            pq.push(num);
            minVal = min(minVal, num);
        }

        int ans = INT_MAX;
        while(1){
            int maxVal = pq.top();
            if(maxVal % 2 != 0)
                break;

            pq.pop();
            maxVal /= 2;
            pq.push(maxVal);
            minVal = min(minVal, maxVal);
            ans = min(ans, pq.top()-minVal);
        }
        return ans;
    }
};
