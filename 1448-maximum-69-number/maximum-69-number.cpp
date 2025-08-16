class Solution {
public:
    int maximum69Number (int num) {
        int mul = 1, res = -1 ;
        int temp = num ;
        while(temp){
            if(temp % 10 == 6){
                res = mul ;
            }
            mul = mul * 10 ;
            temp /= 10 ;
        }

        if(res == -1) return num ;

        return num + 3 * res ;
    }
};