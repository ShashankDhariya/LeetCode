class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int bottles = numBottles;

        int ans = bottles;
        while(bottles >= numExchange){
            int emptyBottles = bottles % numExchange;

            bottles /= numExchange;
            ans += bottles;

            bottles += emptyBottles;
        }

        return ans;
    }
};
