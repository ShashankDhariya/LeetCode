class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        map<int, int> freq;
        vector<int> res;
        
        for(auto num: nums)
            freq[num]++;
        
        priority_queue<int> pq;
        for(auto f: freq)
            pq.push(f.second);
        
        
        while(pq.size() > 1){
            int num1 = pq.top() - 1;
            pq.pop();
            int num2 = pq.top() - 1;
            pq.pop();
            if(num1 > 0)   pq.push(num1);
            if(num2 > 0)   pq.push(num2);
        }
        
        return pq.empty()? 0: pq.top();
    }
};
