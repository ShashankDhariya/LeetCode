class Solution {
public:
    #define ll long long
    
    ll expo(ll a, ll b, ll c){
        ll res = 1;
        while(b > 0){
            if(b & 1)
                res = (res * a) % c;
            a = (a * a) % c;
            b >>= 1;
        }
        return res;
    }
    
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        
        int n = variables.size();
        for(int i=0;i<n;i++){
            auto var = variables[i];
            
            ll res = expo(var[0], var[1], 10);
            res = expo(res, var[2], var[3]);
            
            if(res == target)
                ans.push_back(i);
        }
        
        return ans;
    }
};
