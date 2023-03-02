class Solution {
public:
    int fillCups(vector<int>& amount) {
        int ans = 0;
        priority_queue<int> pq;
        if(amount[0] > 0)   pq.push(amount[0]);
        if(amount[1] > 0)   pq.push(amount[1]);
        if(amount[2] > 0)   pq.push(amount[2]);

        while(pq.size() > 1){
            int c1 = pq.top();
            pq.pop();
            int c2 = pq.top();
            pq.pop();
            
            if(c1 - 1 > 0)
                pq.push(c1-1);

            if(c2 - 1 > 0)
                pq.push(c2-1);
            ans++;
        }
        if(pq.size())
            ans += pq.top();
        return ans;
    }
};
