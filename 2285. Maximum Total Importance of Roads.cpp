class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> m;

        for(auto num: roads){
            m[num[0]]++;
            m[num[1]]++;
        }

        priority_queue<long long> pq;
        for(auto num: m)
            pq.push(num.second);

        long long ans = 0;
        while(!pq.empty()){
            ans += pq.top()*n;
            pq.pop();
            n--;
        }
        return ans;
    }
};
