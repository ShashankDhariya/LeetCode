class Solution {
public:
    
    bool check(int num){
        if(num / 10 == 0)
            return 0;
        
        int n = num;
        int size = 0;
        while(num){
            size++;
            num /= 10;
        }
        
        if(size % 2 == 1)
            return 0;
    
        int a = 0;
        int b = 0;
        num = n;
        for(int i=0;i<size;i++){
            if(i<(size/2))
                a += (num % 10);
            else 
                b += (num % 10);
            num /= 10;
        }
        
        return a == b;
    }
    
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        while(low <= high){
            if(check(low))
                ans++;
            low++;
        }
        
        return ans;
    }
};
