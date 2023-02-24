class KthLargest {
public:
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    KthLargest(int k, vector<int>& nums) {
        priority_queue<int> temp;
        for(auto num: nums)
            temp.push(num);
        
        int key = k;
        while(k-- && !temp.empty()){
            pq.push({temp.top(), key});
            temp.pop();
        }
    }
    
    int add(int val) {
        if(pq.empty())
            pq.push({val, 1});

        else if(pq.size() < pq.top().second)
            pq.push({val, pq.top().second});

        else if(val > pq.top().first){
            pq.pop();
            pq.push({val, pq.top().second});
        }
        return pq.top().first;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
