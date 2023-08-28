class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<int> res(31, 0);
        long long sum = 0;
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            int x = nums[i];
            res[log2(x)]++;
            sum += x;
        }
        
        if(sum < target)
            return -1;
        
        int ans = 0;
        for(int i=0;i<30;i++){
            if((1 << i) & target){
                if(res[i] > 0)
                    res[i]--;
                
                else {
                    int j = i;
                    while(j < 30 && res[j] == 0){
                        j++;
                        ans++;
                    }
                    res[j]--;
                    while(j > i)
                        res[--j]++;
                }
            }
            res[i+1] += res[i] / 2;
        }
        
        return ans;
    }
};
