class Solution {
public:
    string customSortString(string order, string s) {
        int n = order.size();
        unordered_map<char, int> m;
        for(auto o: order)
            m[o] = n--;
        
        priority_queue<pair<int, char>> pq;
        for(auto str:s)
            pq.push({m[str], str});

        string ans = "";
        while(!pq.empty()){
            ans += pq.top().second;
            pq.pop();
        }
        return ans;
    }
};
