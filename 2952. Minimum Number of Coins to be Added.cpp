class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int ans = 0;
        
        unordered_map<int, int> mp;
        for(auto coin: coins)
            mp[coin]++;
        
        long long sum = 0;
        for(int i=1;i<=target;i++){
            if(mp[i])
                sum += ((long long)mp[i] * i);
            
            else {
                if(sum >= i)
                    continue;
                
                else {
                    sum += i;
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
