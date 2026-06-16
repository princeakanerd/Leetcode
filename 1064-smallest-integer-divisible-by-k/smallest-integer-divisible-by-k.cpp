class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int rem = 1 ;
        if(k == 1) return 1;
        int prev = 1 ;
        for(int t = 1 ; t <= k ; t++ ){
            rem = (rem + (prev * 10) % k) % k;
            prev = (prev * 10) % k ;
            if(rem == 0) return t + 1 ;
        }

        return -1 ;
    }
};