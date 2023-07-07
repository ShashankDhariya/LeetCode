class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;

        for(auto a: arr)
            freq[a]++;
        
        int ans = -1;
        for(auto m: freq){
            if(m.first == m.second)
                ans = max(ans, m.first);
        }
        return ans;
    }
};
