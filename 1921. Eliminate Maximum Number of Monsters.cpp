class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> time(0);

        int n = speed.size();
        for(int i=0;i<n;i++)
            time.push_back(ceil(dist[i] / (double)speed[i]));
        sort(time.begin(), time.end());

        int t = 0;
        for(int i=0;i<n;i++){
            if(time[i] == t)
                return i;
            else 
                t++;
        }

        return n;
    }
};
