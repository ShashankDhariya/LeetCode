class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);
        vector<int> ans1(n, 0);
        vector<int> ans2(n, 0);
        int balls = 0;

        for(int i=0;i<n;i++){
            if(i != 0)
                ans1[i] = ans1[i-1] + balls;
            if(boxes[i] == '1') 
                balls++;
        }

        balls = 0;
        for(int i=n-1;i>-1;i--){
            if(i != n-1)
                ans2[i] = ans2[i+1] + balls;
            if(boxes[i] == '1') 
                balls++;
        }

        for(int i=0;i<n;i++)
            ans[i] = ans1[i] + ans2[i];
        return ans;
    }
};
