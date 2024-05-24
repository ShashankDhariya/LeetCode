class Solution {
public:

    bool canTake(vector<pair<int, int>> res, string& word){
        for(auto w: word){
            if(res[w - 'a'].first == 0)
                return 0;

            res[w - 'a'].first--;
        }

        return 1;
    }

    int solution(int idx, int& n, vector<string>& words, vector<pair<int, int>>& res) {
        if(idx == n)
            return 0;

        int taken = 0;
        if(canTake(res, words[idx])){
            int score = 0;
            for(auto w: words[idx]){
                score += res[w - 'a'].second;
                res[w - 'a'].first--;
            }
            taken = score + solution(idx+1, n, words, res);
            for(auto w: words[idx])
                res[w - 'a'].first++;
        }

        int notTaken = solution(idx+1, n, words, res);

        return max(taken, notTaken);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();

        vector<pair<int, int>> res(26, {0, 0});
        int size = letters.size();
        for(int i=0;i<size;i++){
            res[letters[i] - 'a'].first++;
            res[letters[i] - 'a'].second = score[letters[i] - 'a'];
        }

        return solution(0, n, words, res);
    }
};
