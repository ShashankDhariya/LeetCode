class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long ans = -1e9;
        
        int n = maxHeights.size();
        for(int idx=0;idx<n;idx++){
            long long sum = 0;
            
            vector<int> res = maxHeights;
            for(int i=idx;i<n-1;i++){
                if(res[i] < res[i+1])    
                    res[i+1] = res[i];
            }
            
            for(int i=idx;i>0;i--){
                if(res[i-1] > res[i])    
                    res[i-1] = res[i];
            }
            
            for(auto r: res)
                sum += r;
            
            ans = max(ans, sum);
        }
        
        return ans;
    }
};
