class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int i = c;
        int j = d;
        while(i > 0 && j > 0){
            if(i == a && j == b)    break;
            
            if(i == e && j == f)
                return 1;
            i--;
            j--;
        }
        
        i = c;
        j = d;
        while(i <= 8 && j <= 8){
            if(i == a && j == b)   break;
        
            if(i == e && j == f)
                return 1;
            i++;
            j++;
        }
        
        i = c;
        j = d;
        while(i <= 8 && j > 0){
            if(i == a && j == b)    break;
            
            if(i == e && j == f)
                return 1;
            i++;
            j--;
        }
        
        i = c;
        j = d;
        while(i > 0 && j <= 8){
            if(i == a && j == b)    break;
            
            if(i == e && j == f)
                return 1;
            i--;
            j++;
        }
        
        if(a == e){
            if(a == c){
                if(b < f && (d < b || d > f))
                    return 1;

                if(b > f && (d < f || d > b))
                    return 1;
                
                else 
                    return 2;
            }
            
            else 
                return 1;
        }
        if(b == f){         
            if(b == d){
                if(a < e && (c < a || c > e))
                    return 1;

                if(a > e && (c < e || c > a))
                    return 1;
                
                else 
                    return 2;
            }
            
            else 
                return 1;
            
        }
        
        return 2;
    }
};
