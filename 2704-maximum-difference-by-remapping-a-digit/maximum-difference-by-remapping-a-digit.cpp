class Solution {
public:

    int minMaxDifference(int num) {
        vector<int> digits ;
        int temp = num ;
        while(num){
            digits.push_back(num % 10) ;
            num /= 10 ;
        }

        reverse(digits.begin() , digits.end()) ;
        int mystery = -1 ;
        for(int i = 0 ; i < digits.size() ; i ++ ) {
            if(digits[i] != 9) {
                mystery = digits[i] ;
                break ;
            }
        }

        int mul = 1 ;
        for(int i = digits.size() - 1 ; i >= 0 ; i-- ){
            num += mul * (digits[i] == mystery ? 9 : digits[i]) ;
            mul *= 10 ;
        }

        int maxi = num ;
        mystery = digits[0];
        int mini = 0 ;
        mul = 1;
        for(int i = digits.size() - 1 ; i >= 0; i-- ){
            mini += mul * (digits[i] == mystery ? 0 : digits[i]) ;
            mul *= 10 ;
        }
        
        return maxi - mini;
        
        
 


    }
};