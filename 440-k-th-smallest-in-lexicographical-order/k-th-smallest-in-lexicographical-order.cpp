class Solution {
public:
    int countsteps(long long n , long long pfx1 , long long pfx2){
        long long cnt = 0 ;
        while(pfx1 <= n){
            cnt += min(n + 1 , pfx2) - pfx1 ;
            pfx1 *= 10 ;
            pfx2 *= 10 ;
        }
        return cnt ;
    }
    int findKthNumber(int n, int k) {
        long long curr = 1 ; k-- ;

        while(k){
            long long steps = countsteps(n , curr , curr + 1) ;
            if(steps <= k){
                curr ++ ;
                k -= steps ;
            } else {
                curr *= 10 ;
                k -- ;
            }

        }
        return curr ;
    }
};