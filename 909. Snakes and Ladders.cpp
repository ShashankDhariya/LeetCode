class Solution {
public:  
    vector<int> cordinates(int pos,int n){
        int r = n - (pos-1) / n - 1;
        int c = (pos-1) % n;
        if(r % 2 == n % 2)
            return {r,n-1-c};
        else
            return {r,c};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n= board.size();
        int ans = 0;
        queue<int> q;

        vector<vector<bool>> visited(n, vector<bool>(n, false)); 
        q.push(1);
        visited[n-1][0]=true;

        while(!q.empty()){
            int size=q.size();   
            for(int i=0;i<size;i++){
                int front = q.front();
                q.pop();

                if(front == n*n) 
                    return ans;
                
                for(int k=1;k<=6;++k){
                    if(k + front > n*n) 
                        break;

                    vector<int>pos = cordinates(front + k, n);
                    int r = pos[0];
                    int c = pos[1];
                    if(visited[r][c] == true) 
                        continue;
                    visited[r][c] = true;
                    
                    if(board[r][c] != -1)
                        q.push(board[r][c]);
                    else
                        q.push(front + k);
                }
            }
            ans++;
        }
        return -1;
    }
};
