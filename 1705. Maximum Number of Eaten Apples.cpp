class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i=0;i<n || pq.size();i++){
            while(pq.size() && pq.top().first < i)
                pq.pop();

            if(i < n && apples[i])
                pq.push({i + days[i] - 1, min(apples[i], days[i])});
            
            if(pq.empty())
                continue;

            int day = pq.top().first;
            int apple = pq.top().second;
            pq.pop();

            if(apple){
                apple--;
                ans++;
            }

            if(apple && day > i)
                pq.push({day, apple});
        }
        return ans;
    }
};
