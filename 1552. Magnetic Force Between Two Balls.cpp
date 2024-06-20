class Solution {
public:

    int check(vector<int>& position, int& n, int& m, int& force){
        int balls = 1;
        int prev = position[0];
        for(int i=0;i<n;i++){
            if(position[i] - prev >= force){
                balls++;
                prev = position[i];
            }
        }

        return balls;
    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        int ans = 0;
        sort(position.begin(), position.end());

        int left = 1;
        int right = 1e9;
        while(left <= right){
            int force = left + (right - left) / 2;

            if(check(position, n, m, force) >= m){
                ans = force;
                left = force + 1;
            }

            else 
                right = force - 1;
        }

        return ans;
    }
};
