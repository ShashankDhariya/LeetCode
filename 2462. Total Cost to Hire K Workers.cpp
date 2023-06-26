class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        if(k > n)
            return -1;

        priority_queue<int> left;
        priority_queue<int> right;

        int i = 0;
        int j = n-1;
        while(i<candidates)
            left.push(-costs[i++]);

        while(j >= i && candidates){
            right.push(-costs[j--]);
            candidates--;
        }

        long long ans = 0;
        while(k--){
            int l = INT_MAX;
            int r = INT_MAX;

            if(!right.empty())  r = -right.top();
            
            if(!left.empty())   l = -left.top();

            if(l <= r){
                left.pop();
                ans += l;
                if(i <= j)
                    left.push(-costs[i++]);
            }
            else{
                right.pop();
                ans += r;
                if(i <= j)
                    right.push(-costs[j--]);
            }
        }
        return ans;
    }
};
