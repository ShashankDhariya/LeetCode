class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    
    set<int> list;
    void addNum(int value) {
        list.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        int s = -1;
        int e = -1;

        for(auto l: list){
            if(s < 0)
                s = e = l;
            
            else if(l - e == 1)
                e = l;
            
            else{
                ans.push_back({s, e});
                s = e = l;
            }
        }
        ans.push_back({s, e});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
