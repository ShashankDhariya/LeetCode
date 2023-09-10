class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy)
            return t != 1;
            
        int a = abs(sy - fy);
        int b = abs(sx - fx);
        
        long long res = max(a, b);
        
        return res <= t;
    }
};
