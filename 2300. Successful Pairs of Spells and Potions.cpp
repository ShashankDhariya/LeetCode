class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;    
        sort(potions.begin(), potions.end());
        int m = spells.size();
        int n = potions.size();

        for(int i=0;i<m;i++){
            int left = 0;
            int right = n - 1;
            while(left <= right){
                int  mid = left + (right - left) / 2;
                long long res = (long long)spells[i] * (long long)potions[mid];
                if(res >= success)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            ans.push_back(n - left);
        }
        return ans;
    }
};
