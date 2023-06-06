class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if(arr.size() <= 2)
            return 1;

        int n = arr.size();
        int a = INT_MAX;
        int an = INT_MIN;
        for(auto num: arr){
            a = min(a, num);
            an = max(an, num);
        }

        if((an - a) % (n-1) != 0)
            return 0;
        int d = (an - a) / (n-1);
    
        int i = 0;
        while(i < n){
            if(arr[i] == a+i*d)
                i++;
            
            else if((arr[i] - a) % d != 0) 
                return 0;
            
            else{
                int idx = (arr[i]-a)/d;
                if(idx < i || arr[idx] == arr[i])
                    return 0;
                swap(arr[i], arr[idx]);
            }
        }
        return 1;
    }
};
