class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        priority_queue<pair<int, int>> pq;
        for(int i=0;i<n;i++)
            pq.push({score[i], i});

        int rank = 1;
        while(!pq.empty()){
            string str;
            int i = pq.top().second;
            if(rank == 1)
                str = "Gold Medal";
            else if(rank == 2)
                str = "Silver Medal";
            else if(rank == 3)
                str = "Bronze Medal";
            else 
                str = to_string(rank);
            ans[i] = str;
            pq.pop();
            rank++;
        }
        return ans;
    }
};
