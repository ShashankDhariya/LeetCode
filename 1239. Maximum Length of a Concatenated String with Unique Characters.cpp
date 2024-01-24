class Solution {
public:
    int solution(int i, int freq, vector<string>& arr){
        if(i == arr.size())
            return 0;

        bool canTake = 1;
        int temp = freq;
        for(auto ch: arr[i]){
            if(freq & (1 << (ch - 'a'))){
                canTake = 0;
                break;
            }
            freq |= (1 << (ch - 'a'));
        }

        int taken = 0;
        if(canTake)
            taken = arr[i].length() + solution(i+1, freq, arr);
        int notTaken = solution(i+1, temp, arr);

        return max(taken, notTaken);
    } 

    int maxLength(vector<string>& arr) {
        return solution(0, 0, arr);
    }
};
