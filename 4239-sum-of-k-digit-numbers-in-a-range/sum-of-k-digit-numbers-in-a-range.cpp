class Solution {
    using ll = long long;
    const int mod = 1e9 + 7 ;
public:
    ll binexp(ll a, ll b){
        ll res = 1 ;
        while(b){
            if(b & 1) res = res * a % mod ;
            a = a * a % mod ;
            b >>= 1;
        }
        return res % mod;
    }
    ll invmod(ll a){
        return binexp(a, mod - 2) ;
    }
    int sumOfNumbers(int l, int r, int k) {
        ll freq = binexp(r - l + 1, k - 1) ;
        //used gpsum formula for 1, 10, 100 ...
        ll gpsum = ((binexp(10, k) - 1 + mod) % mod) * invmod(10 - 1) ;
        


        ll sum = 0 ;
        for(int i = l ; i <= r; i++ ){
            sum += i;
        }

        return 1ll * ((sum * gpsum % mod) * freq )% mod ;

    }
};