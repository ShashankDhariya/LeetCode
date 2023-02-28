class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;

        int n = operations.size();
        for(auto o:operations){
            if(o[1] == '+')
                ans++;
            else 
                ans--;
        } 
        return ans;
    }
};
