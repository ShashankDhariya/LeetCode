class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> res;

        for(int i=0;i<n;i++)
            res.push_back({capital[i], profits[i]});
        sort(res.begin(), res.end());

        int i = 0;
        priority_queue<int> pq;
        while(k--){
            while(i < n && res[i].first <= w){
                pq.push(res[i].second);
                i++;
            }
            
            if(pq.empty())
                break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
