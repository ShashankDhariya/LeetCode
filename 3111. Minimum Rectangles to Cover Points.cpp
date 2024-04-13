class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int ans = 0;
        
        sort(points.begin(), points.end());
        int n = points.size();
        for(int i=0;i<n;i){
            long long newX = points[i][0] + w;
            
            int left = i+1;
            int right = n-1;
            while(left < right){
                int mid = left + (right - left) / 2;
                
                if(points[mid][0] > newX)
                    right = mid;
                
                else 
                    left = mid + 1;
            }
            
            if(left < n && points[left][0] <= newX)    
                left++;
            
            i = left;
            ans++;
        }
        
        return ans;
    }
};
