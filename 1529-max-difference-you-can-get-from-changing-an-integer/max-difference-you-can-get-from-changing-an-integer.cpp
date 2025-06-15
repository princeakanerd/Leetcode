class Solution {
public:
    int maxDiff(int num) {
        vector<int> digits;

        int temp = num ;
        while(temp){
            digits.push_back(temp % 10) ;
            temp /= 10 ;
        }

        reverse(digits.begin(), digits.end()) ;
        bool issame = true ;

        for(int i = 1 ; i < digits.size() ; i++ ){
            if(digits[i] != digits[i - 1]) issame = false ;
        }
        int mul = 1;
        if(issame){
            
            int res = 0 ;
            for(int i = 0 ; i < digits.size() ; i++ ){
                res += 8 * mul ;
                mul *= 10 ;
            }
            return res ;
        }
        int maxmystery = -1 ;
        for(int i = 0 ; i < digits.size() ; i++ ) {
            if(digits[i] != 9){
                maxmystery = digits[i] ;
                break ;
            }
        }

        int maxnum = 0, minnum = 0 ;
        mul = 1 ;
        for(int i = digits.size() - 1 ; i >= 0 ; i--){
            maxnum += mul * (digits[i] == maxmystery ? 9 : digits[i]);
            mul *= 10 ;
        }
        mul = 1 ;
        int j = 0 ;
        while(j < digits.size() && (digits[j] == 1 || digits[j] == 0)) j ++ ;
        int minmystery = digits[j];

        for(int i = digits.size() - 1 ; i >= 0 ; i--){  
            int factor = (minmystery == digits[0]) ? 1 : 0 ;
            minnum += mul * (minmystery == digits[i]? factor : digits[i]);
            mul *= 10 ;
        }

        return maxnum - minnum ;

        
        
    }
};