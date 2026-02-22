class Solution {
public:
    int binaryGap(int n) {
        int cnt = -100 ; 
        int res = 0 ;
        while(n){
            if(n % 2){
                res = max(res, cnt) ;
                cnt = 1 ;
            } else cnt ++ ;
             n/= 2;
        }
        return res;
    }
};