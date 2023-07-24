class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        
        int dominant = -1;
        unordered_map<int, int> freq;
        for(int i=0;i<n;i++)
            freq[nums[i]]++;
        
        for(auto f: freq){
            if(f.second * 2 > n)
                dominant = f.first;
        }
        
        int f = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == dominant){
                f++;
                freq[nums[i]]--;
                if(((freq[nums[i]] * 2) > n-1-i) && ((f*2) > (i+1)))
                    return i;
            }
        }
        
        return -1;
    }
};
