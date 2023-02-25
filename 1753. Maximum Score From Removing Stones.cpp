class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int ans = 0;
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);

        while(pq.size() > 1){
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            if(--s1)
                pq.push(s1);
            if(--s2)
                pq.push(s2);
            ans++;
        }
        return ans;
    }
};
