class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int r = right.size();
        int l = left.size();

        int res1 = r? n - *min_element(right.begin(), right.end()): 0;
        int res2 = l? *max_element(left.begin(), left.end()): 0;

        return max(res1, res2);
    }
};
