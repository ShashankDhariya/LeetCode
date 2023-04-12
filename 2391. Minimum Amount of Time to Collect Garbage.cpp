class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n  = garbage.size();
        int ans = 0;
        int l1 = -1;
        int l2 = -1;
        int l3 = -1;

        for(int i=0;i<n;i++){
            int r1 = 0;
            int r2 = 0;
            int r3 = 0;
            r1 = count(garbage[i].begin(), garbage[i].end(), 'M');
            r2 = count(garbage[i].begin(), garbage[i].end(), 'P');
            r3 = count(garbage[i].begin(), garbage[i].end(), 'G');
            ans += (r1+r2+r3);
            if(r1 != 0)
                l1 = i;

            if(r2 != 0)
                l2 = i;

            if(r3 != 0)
                l3 = i;
        }

        for(int i=0;i<n;i++){
            if(i < l1)
                ans += travel[i];
            if(i < l2)
                ans += travel[i];
            if(i < l3)
                ans += travel[i];
        }
        return ans;
    }
};
