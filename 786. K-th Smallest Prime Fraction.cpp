class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<double, vector<double>, greater<double>> pq;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
                pq.push(arr[i] / (double)arr[j]);
        }

        double ans; 
        while(!pq.empty() && k--){
            ans = pq.top();
            pq.pop();
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
                if((arr[i] / (double)arr[j]) == ans)
                    return {arr[i], arr[j]};
        }
        return {};
    }
};
