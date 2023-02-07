class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0;
        int j = 0;
        int n = fruits.size();
        unordered_map<int, int> res;

        for(j=0;j<n;j++){
            res[fruits[j]]++;
            if(res.size() > 2){
                res[fruits[i]]--;
                if(res[fruits[i]] == 0)
                    res.erase(fruits[i]);
                i++;
            }
        }
        return j-i;
    }
};
