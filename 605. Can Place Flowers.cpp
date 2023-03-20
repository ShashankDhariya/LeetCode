class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans = 0;
        int size = flowerbed.size();
        
        for(int i=0;i<size;i++){
            if(!n)
                break;
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == size-1 || flowerbed[i+1] == 0)){
               flowerbed[i] = 1;
               n--;
            }
        }
        return !n;
    }
};
