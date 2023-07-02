class Solution {
public:
    
    bool isPrime(int n){
        int size = sqrt(n);
        for(int i=2;i<=size;i++){
            if(n % i == 0)
                return 0;
        }
        return 1;
    }
    
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> ans;
        
        for(int i=2;i<=n/2;i++){
            if(!isPrime(i)) 
                continue;
            if(!isPrime(n-i))
                continue;
            
            ans.push_back({i, n-i});
        }
        return ans;
    }
};
