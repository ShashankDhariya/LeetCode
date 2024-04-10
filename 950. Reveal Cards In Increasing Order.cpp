class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());

        deque<int> dq;
        int n = deck.size();
        for(int i=0;i<n;i++)    
            dq.push_back(i);
            
        int idx = 0;
        vector<int> ans(n);
        while(!dq.empty()){
            ans[dq.front()] = deck[idx++];
            dq.pop_front();

            if(!dq.empty()) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }

        return ans;
    }
};
