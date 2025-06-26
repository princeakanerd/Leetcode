class Solution {
public:
    // bool check(int idx , string &s , int k) {
    //     int n = s.length() ;
    //     long long mul = 1 ;
    //     long long num = 0 ;
    //     for(int i = n - 1 ;i >= idx ; i--) {
    //             if(s[i] == '1'){
    //                 num += mul ;
    //             }
    //             if(num > k || mul > k) return false ;
    //             mul *= 2;
    //     }
    //     return true ;
    // }
    int longestSubsequence(string s, int k) {
        int cnt = s.length() ;
        int n = s.length() ;
        long long mul = 1 , num = 0 ;
        int idx = -1 ;
        for(int i = n - 1 ;i >= 0 ; i-- ){
            if(s[i] == '1') {
                num += mul ;
            }
            if(mul > k || num > k) {idx = i ;break ;}
            mul *= 2;

            
        }    

        for(int i = 0 ;i <= idx ; i++ ){
            cnt -= (s[i] == '1') ;
        }
        
        return cnt ;
    }
};