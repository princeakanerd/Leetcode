class Solution {
public:
    

     long long pal(long long num , bool odd) {
        string a = to_string(num) ;
        string b = a , c = a ;
        reverse(b.begin() , b.end()) ;
        c.pop_back() ;
        a = a + b ;
        c = c + b;

        if(odd) return stoll(c) ;
        return stoll(a) ;

    }
    bool ismirror(long long num , long long k) {
        long long temp = num ;
        string res ;
        while(temp) {
            res.push_back(temp % k + '0') ;
            temp /= k ;
        }
        int n = res.length() ;
        for(int i = 0 ;i < n/ 2; i++ ) {
            if(res[i] != res[n - i - 1]) return false ;
        }
        return true ;

    }
    long long kMirror(int k, int n) {

        long long sum = 0 ;

        for(int len = 1 ; n > 0 ; len *= 10) {
            for(int i = len ; n > 0 && i < len * 10 ; i++ ) {
                long long num = pal(i , true) ;
                if(ismirror(num , k)){
                    sum += num ;
                    n-- ;
                }
            }

            for(int i = len ; n > 0 && i < len * 10 ; i++ ) {
                long long num = pal(i , false) ;
                if(ismirror(num , k)){
                    sum += num ;
                    n-- ;
                }
            }

        }

        return sum ;

    }
};