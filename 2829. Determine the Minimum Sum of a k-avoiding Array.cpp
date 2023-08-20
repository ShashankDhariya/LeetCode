class Solution {
public:
    int minimumSum(int n, int k) {
        vector<int> res;
        
        int sum = 0;
        unordered_map<int, bool> mp;
        
        int num = 1;
        while(n){
            if(mp[k - num])
                num++;
            else {
                mp[num] = 1;
                sum += num;
                num++;
                n--; 
            }
        }
        
        return sum;
    }
};
