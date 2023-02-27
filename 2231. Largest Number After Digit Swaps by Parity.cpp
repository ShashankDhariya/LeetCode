class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> even;
        priority_queue<int> odd;
        vector<int> res;

        while(num){
            int r = num % 10;
            if(r % 2 == 0)
                even.push(r);
            else 
                odd.push(r);
            res.push_back(r);
            num /= 10;
        }

        int n = res.size();
        reverse(res.begin(), res.end());

        int ans = 0;
        for(int i=0;i<n;i++){
            if(res[i] % 2 == 0){
                ans = ans*10 + even.top();
                even.pop();
            }
            else{
                ans = ans*10 + odd.top();
                odd.pop();
            }
        }
        return ans;
    }
};
