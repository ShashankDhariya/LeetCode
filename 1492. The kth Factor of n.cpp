class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        for(int i=1;i<=sqrt(n);i++){
            if(n % i == 0)
                factors.push_back(i);
        }

        int size = factors.size();
        for(int i=size-1;i>-1;i--){
            int fact = n / factors[i];
            if(fact == factors[i])
                continue;
            factors.push_back(fact);
            size++;
        }

        return k <= (size)? factors[k-1]: -1;
    }
};
