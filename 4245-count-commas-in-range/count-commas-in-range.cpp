class Solution {
    using ll = long long ;
public:
    long long countCommas(long long n) {
        long long cnt = 0 ;

        for(ll i = 1000 ; i <= 1e15 ; i *= 1000 ){
            if(n >= i){
                cnt += 1ll * (log(i) / log(1000)) * (min(n, i * 1000 - 1) - i + 1) ;
            } else break ;
            cout << cnt << endl;
        }

        return cnt ;
    }
};