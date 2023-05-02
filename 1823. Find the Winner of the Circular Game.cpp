class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=0;i<n;i++)
            q.push(i+1);

        while(q.size() > 1){
            for(int i=0;i<k-1;i++){
                int num = q.front();
                q.pop();
                q.push(num);
            }
            q.pop();
            cout<<q.front()<<" ";
        }
        return q.front();
    }
};
