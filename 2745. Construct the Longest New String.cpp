class Solution {
public:
    int longestString(int x, int y, int z) {
        int num = min(x, y);
        
        if(x - y != 0)
            num += (num+1);
        else
            num += num;
        return (num+z)+(num+z);
    }
};
