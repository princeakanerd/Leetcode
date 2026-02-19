class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length() ;
        int res = 0 ;
        
        int i = 0 ;
        while(i < n && s[i] == '1') i++ ;
        while(i < n){
            int cnt0 = 0, cnt1 = 0 ;
            while(i < n && s[i] == '0'){
                cnt0++ ; i++ ;
            }

            while(i < n && s[i] == '1'){
                cnt1++; i++;
            }

            res += min(cnt0, cnt1) ;
        }


         i = 0 ;

        while(i < n && s[i] == '0') i++ ;
        while(i < n){
            int cnt0 = 0, cnt1 = 0 ;
            while(i < n && s[i] == '1') {
                cnt1++ ;
                i++ ;
            }

            while(i < n && s[i] == '0') {
                cnt0++ ;
                i++ ;
            }

            res +=min(cnt0,cnt1 ) ;
        }

        return res;
    }
};