class Solution {
public:
    int nextGreaterElement(int n) {
        string res = to_string(n);  

        int size = res.size();
        for(int i=size-2;i>-1;i--){
            if(res[i] < res[i+1]){
                reverse(res.begin() + i + 1, res.end());

                int j = i+1;
                while(j < size && res[j] <= res[i])
                    j++;

                if(j < n)
                    swap(res[i], res[j]);
                break;
            }
        }

        long long num = stol(res);
        if(n == num || num > INT_MAX)
            return -1;
        return num;
    }
};
