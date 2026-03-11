class Solution {
public:
    
    int bitwiseComplement(int n) {
        if(n == 0) return 1 ;
        int digs = log2(n) + 1 ;
        int num = (1 << digs) - 1;
        return num ^ n ;
    }
};