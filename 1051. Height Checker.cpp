class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> freq(101, 0);
        for(auto h: heights)
            freq[h]++;

        int ans = 0;
        int num = 1;
        for(auto h: heights){
            while(num < 101 && freq[num] == 0)
                num++;

            ans += (num != h);
            freq[num]--;
        }

        return ans;
    }
};
