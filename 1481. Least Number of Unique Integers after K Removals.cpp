class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for(auto a: arr)
            freq[a]++;

        vector<int> res;
        for(auto f: freq)
            res.push_back(f.second);

        sort(res.begin(), res.end());
        int ans = res.size();
        for(auto r: res){
            k -= r;
            if(k < 0)
                break;
            ans--;
        }

        return ans;
    }
};
