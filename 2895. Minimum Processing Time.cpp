class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int ans = 0;
        sort(tasks.begin(), tasks.end());
        sort(processorTime.begin(), processorTime.end());
        
        int n = processorTime.size();
        int task = tasks.size() - 1;
        
        int part = ceil((task + 1) / (double)n);
        for(int i=0;i<n;i++){
            int time = 0;
            
            for(int p=0;p<part;p++){
                if(task > -1){
                    int currTime = tasks[task--];
                    time = max(time, currTime);
                }
            }
            
            ans = max(ans, processorTime[i] + time);
        }
        
        return ans;
    }
};
