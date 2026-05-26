class Solution {
public:
    int popcnt(int num){
        int cnt = 0 ;
        while(num){
            if(num % 2) cnt ++ ;
            num /=2 ;
        }

        return cnt ;
    }
    int numberOfSpecialChars(string word) {
        int num = 0, num2 = 0 ;
        int n = word.size() ;
        for(int i = 0 ;i < n ; i++ ){
            if(word[i] >= 'a' && word[i] <= 'z'){
                int val = word[i] - 'a' ;
                int bit = (1 << val) ;
                num |= bit ;
            } else {
                int val = word[i] - 'A' ;
                int bit = (1 << val) ;
                num2 |= bit ;
            }
        }
        int temp = num2 & num;
        return popcnt(temp) ;

    }
};