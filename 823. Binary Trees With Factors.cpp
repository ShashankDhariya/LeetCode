class Solution {
public:
    #define MOD 1000000007
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int, long long int> m;
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<arr.size();i++){
            m.insert({arr[i], 1});
        }
        
        for(int i=1;i<arr.size();i++){
            auto it = m.find(arr[i]);
            long long int count = 0;
            for(int j=0;j<i;j++){
                if(arr[i] % arr[j] == 0){
                    int a = arr[i] / arr[j];
                    auto it1 = m.find(a);
                    auto it2 = m.find(arr[j]);
                    if(it1 != m.end()){
                        count += it1->second *  it2->second;
                    }
                }
            }
            it->second += count;
        }
        
        long long int ans = 0;
        for(auto i=m.begin();i!=m.end();i++)
            ans += i->second;
        
        return ans%MOD;
    }
};

/*
OR
class Solution {
public:
    int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        long long ans = 0;
        sort(arr.begin(), arr.end());

        unordered_map<int, long long> dp;
        int n = arr.size();
        for(int i=0;i<n;i++){
            dp[arr[i]] = 1;
            for(int j=0;j<i;j++){
                if(arr[i] % arr[j] == 0)
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[arr[i] / arr[j]]) % mod;
            }
            ans = (ans + dp[arr[i]]) % mod;
        }

        return ans;
    }
};
*/
