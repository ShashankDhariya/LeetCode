class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        double ans = 0;

        int min = INT_MAX;
        int max = INT_MIN;
        for(int s: salary){
            if(s > max)
                max = s;
            if(s < min)
                min = s;
            ans += s;
        }
        return (ans - min - max) / (n-2);
    }
};
