class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    
    vector<int> list;
    void addNum(int value) {
        list.push_back(value);
    }
    
    vector<vector<int>> getIntervals() {
        set<vector<int>> ans;
        int n = list.size();
        sort(list.begin(), list.end());
        auto s = list[0];
        auto e = list.back();
        vector<int> res = {s, e};

        for(int i=1;i<n;i++){
            if(list[i-1] == list[i])
                continue;
            if(list[i-1] != list[i] - 1){
                res[1] = list[i-1];
                ans.insert(res);
                res[0] = list[i];
                res[1] = list[n-1];
            }
        }
        ans.insert(res);
        vector<vector<int>> a(ans.begin(), ans.end());
        return a;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
