class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int res1 = 0;
        int res2 = 0;
        for(auto m: moves){
            if(m == 'R')
                res1--;
            else 
                res1++;
            
            if(m == 'L')
                res2--;
            else 
                res2++;
        }
        
        return max(res1, res2);
    }
};
