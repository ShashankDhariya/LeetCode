class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int f = 0;
        int s = 0;
        
        unordered_map<int, int> freq1;
        for(auto num: nums1)
            freq1[num]++;
        
        unordered_map<int, int> freq2;
        for(auto num: nums2)
            freq2[num]++;
        
        for(auto& freq: freq1){
            if(freq.second > 1){
                f += (freq.second-1);
                freq.second = 1;
            }
        }
        
        for(auto& freq: freq2){
            if(freq.second > 1){
                s += (freq.second-1);
                freq.second = 1;
            }
        }
        
        int n1 = nums1.size();
        for(auto num: nums1){
            if(f >= n1/2)
                break;

            if(freq1.find(num) == freq1.end())
                continue;

            if(freq2.find(num) != freq2.end()){
                freq1[num]--;
                f++;
                if(freq1[num] == 0)
                    freq1.erase(num);   
            }
        }
        
        int n2 = nums2.size();
        for(auto num: nums2){
            if(s >= n2/2)
                break;

            if(freq2.find(num) == freq2.end())
                continue;

            if(freq1.find(num) != freq1.end()){
                s++;
                freq2[num]--;
                if(freq2[num] == 0)
                    freq2.erase(num);   
            }
        }
        
        unordered_set<int> st;
        for(auto& freq: freq1)
            st.insert(freq.first);
        for(auto& freq: freq2)
            st.insert(freq.first);
        
        int ans = st.size();
        if(f < n1/2)
            ans -= (n1/2 - f);
            
        if(s < n2/2)
            ans -= (n2/2 - s);
    
        return ans;
    }
};
