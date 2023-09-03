class Solution {
public:
    
    
    int check(string num, string str){
        int ans = 100;
        for(int i=num.size()-1;i>=0;i--){
            if(num[i] == str[1]){
                for(int j=i-1;j>=0;j--){
                    if(num[j] == str[0]){
                        int res = (num.size() - i - 1) + (i - j - 1);
                        return res;
                    }
                }
            }
        }
        return ans;
    }
    
    int minimumOperations(string num) {
        int ans = num.size();
        
        ans = min(ans, check(num, "25"));
        ans = min(ans, check(num, "50"));
        ans = min(ans, check(num, "75"));
        ans = min(ans, check(num, "00"));
        
        bool zero = 0;
        for(int i=0;i<num.size();i++){
            if(num[i] == '0')
                zero = 1;
        }
        
        if(zero)    ans = min(ans, (int)num.size() - 1);
        
        return ans;
    }
};
