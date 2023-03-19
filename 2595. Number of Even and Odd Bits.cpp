class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> res;
        
        while(n){
            res.push_back(n%2);
            n /= 2;
        }
        
        int even = 0;
        int odd = 0;
        for(int i=0;i<res.size();i++){
            if(i % 2 == 0){
                if(res[i] == 1)  
                    even++;
            }
            else{
                if(res[i] == 1)  
                    odd++;
            }
        }
        
        return {even, odd};
    }
};
