class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();

        priority_queue<int> max;
        priority_queue<int> min;
        for(int i=0;i<n-1;i++){
            min.push(weights[i] + weights[i+1]);
            max.push(-(weights[i] + weights[i+1]));
            if(max.size() == k){
                max.pop();
                min.pop();
            }
        }
        long long mini = 0;
        long long maxi = 0;
        while(!max.empty()){
            maxi += -max.top();
            mini += min.top();
            max.pop();
            min.pop();
        }

        return maxi - mini;
    }
};
