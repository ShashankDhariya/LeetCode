class Solution {
public:
    
    long long fun(string s, int select, int one, int zero, int n){
        long long cost = 0;
        int selected = select;
        for(int i=((n+1)/2)-1;i>-1;i--){
            if(s[i] - '0' == selected){
                cost += i+1;
                selected = abs(1-selected);
            }
        }
        
        selected = select;
        for(int i=((n+1)/2);i<n;i++){
            if(s[i] - '0' == selected){
                cost += n-i;
                selected = abs(1-selected);
            }
        }
        return cost;
    }
    
    long long minimumCost(string s) {
        int n = s.length();
        int one = 0;
        int zero = 0;
        
        for(int i=0;i<n;i++){
            if(s[i] == '0')
                zero++;
            else 
                one++;
        }
        if(!zero || !one || n <= 1)
            return 0;
        
        long long a = fun(s, 0, one, zero, n);
        long long b = fun(s, 1, one, zero, n);
        return min(a, b);
    }
};
