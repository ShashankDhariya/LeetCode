class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        for(auto num: nums)
            freq[num]++;
        
        int ans = 0;
        for(auto f: freq){
            int fe = f.second;
            if(fe % 3 == 0)
                ans += (fe / 3);
            
            else if(fe % 3 == 2)
                ans += ((fe / 3) + 1);
            
            else {
                if(fe >= 4){
                    ans += 2;    
                    fe -= 4;
                    if(fe % 3 == 0)
                        ans += (fe / 3);
                
                    else if(fe % 2 == 0)
                        ans += (fe/2);
                }
                
                else 
                    return -1;
            }
        }
        
        return ans;
    }
};
