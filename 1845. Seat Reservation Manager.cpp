class SeatManager {
public:
    int end = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n) {
        
    }
    
    int reserve() {
        if(pq.empty())
            return ++end;

        else {
            int top = pq.top();
            pq.pop();
            return top;
        }
    }
    
    void unreserve(int seatNumber) {
        if(end == seatNumber)
            end--;

        else
            pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
