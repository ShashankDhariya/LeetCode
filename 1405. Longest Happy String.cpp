class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        char prev = 'Q';
        string ans = "";
        priority_queue<pair<int, char>> pq;
        if(a)   pq.push({a, 'a'});
        if(b)   pq.push({b, 'b'});
        if(c)   pq.push({c, 'c'});

        while(pq.size() > 1){
            auto curr = pq.top();
            pq.pop();
            auto next = pq.top();
            pq.pop();

            if(curr.first >= 2){
                curr.first -= 2;
                ans += curr.second;
                ans += curr.second;
            }
            else {
                curr.first -= 1;
                ans += curr.second;
            }

            if(next.first >= 2 && next.first > curr.first){
                next.first -= 2;
                ans += next.second;
                ans += next.second;
            }
            else {
                next.first -= 1;
                ans += next.second;
            }

            if(curr.first)
                pq.push(curr);
            if(next.first)
                pq.push(next);
        }
        if(pq.empty())
            return ans;
            
        auto curr = pq.top();
        if(curr.first >= 2){
            curr.first -= 2;
            ans += curr.second;
            ans += curr.second;
        }
        else {
            curr.first -= 1;
            ans += curr.second;
        }
        return ans;
    }
};
