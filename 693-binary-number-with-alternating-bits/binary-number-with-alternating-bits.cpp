class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        int prev = -1 ;

        while(n){
            if(prev == -1){
                prev = n % 2;
            } else if(prev !=1 - n % 2) return false ;
            prev = n % 2;

            n /=2 ;
        }
        return true ;
    }
};