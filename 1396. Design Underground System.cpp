class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkI;
    unordered_map<string, pair<double, int>> details;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkI[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto d1 = checkI[id];
        auto d2 = details[d1.first+'-'+stationName];
        int time = d2.first + (t-d1.second);
        int count = d2.second + 1;
        details[d1.first+'-'+stationName] = {time, count};
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto num = details[startStation+'-'+endStation];
        return num.first / num.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
