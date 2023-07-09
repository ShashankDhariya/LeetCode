class Solution {
public:

    int solution(string s){
        int n = s.length();
        int ans = 0;

        unordered_map<char, int> freq;
        for(auto c: s)  freq[c]++;

        for(char ch1='a';ch1<='z';ch1++){
            for(char ch2='a';ch2<='z';ch2++){
                if(ch1 == ch2 || freq[ch1] == 0 || freq[ch2] == 0)
                    continue;

                int ctr1 = 0;
                int ctr2 = 0;
                for(auto c: s){
                    ctr1 += c==ch1;
                    ctr2 += c==ch2;

                    if(ctr1 < ctr2)
                        ctr1 = ctr2 = 0;

                    if(ctr1 > 0 && ctr2 > 0)
                        ans = max(ans, ctr1 - ctr2);
                }
            }
        }
        return ans;
    }

    int largestVariance(string s) {
        int ans1 = solution(s);
        reverse(s.begin(), s.end());
        int ans2 = solution(s);
        return max(ans1, ans2);
    }
};
