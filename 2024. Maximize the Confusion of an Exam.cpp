class Solution {
public:

    int longestRes(string answerKey, char notSelected, int k){
        int n = answerKey.length();
        int ans = 0;
        int i = 0;
        int j = 0;

        while(i < n && j < n){
            if(answerKey[j] == notSelected) {
                if(k)
                    k--;
                else{
                    while(i < n && answerKey[i] != notSelected)
                        i++;
                    i++;
                }
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(longestRes(answerKey, 'F', k), longestRes(answerKey, 'T', k));
    }
};
