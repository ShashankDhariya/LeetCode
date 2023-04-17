class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;

        set<int> s;
        for(int i=0;i<n;i++){
            if(digits[i] % 2 != 0)
                continue;

            for(int j=0;j<n;j++){
                if(j == i)
                    continue;
                for(int k=0;k<n;k++){
                    if(k == j || k == i)
                        continue;
                    if(digits[j] != 0){
                        int num = digits[j] * 100 + digits[k] * 10 + digits[i];
                        s.insert(num);
                    }
                    if(digits[k] != 0){
                        int num = digits[k] * 100 + digits[j] * 10 + digits[i];
                        s.insert(num);
                    }
                }
            }
        }

        for(auto num: s)
            ans.push_back(num);
        return ans;
    }
};
