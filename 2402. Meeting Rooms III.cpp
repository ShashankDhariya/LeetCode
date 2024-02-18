#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<int> room(n, 0);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        
        for(int i=0;i<n;i++)
            freeRooms.push(i);

        int size = meetings.size();
        for(int i=0;i<size;i++){
            while(!pq.empty() && pq.top().first <= meetings[i][0]){
                freeRooms.push(pq.top().second);
                pq.pop();
            }

            if(!freeRooms.empty()){
                room[freeRooms.top()]++;
                pq.push({meetings[i][1], freeRooms.top()});
                freeRooms.pop();
            }

            else {
                ll end = pq.top().first;
                int idx = pq.top().second;

                pq.pop();
                pq.push({end + meetings[i][1] - meetings[i][0], idx});
                room[idx]++;
            }
        }

        return max_element(room.begin(), room.end()) - room.begin();
    }
};
