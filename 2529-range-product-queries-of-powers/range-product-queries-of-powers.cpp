using ll = long long ;

class Solution {
public:

    ll MOD = 1e9 + 7 ;
        
    long long biggestpower(int n){
        long long num1 = 1 ;
        while(num1 <= n){
            num1 *= 2 ;
        }
        
        return num1 / 2;
    }

    long long binexp(ll a , ll b){
        ll res = 1;
        while(b){
            if(b & 1) res = res * a % MOD ;
            a = a * a % MOD ;
            b >>=1 ;
        }
        return res ;
    }

    long long invmod(ll a){
        return binexp(a , MOD - 2) ;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {

            vector<long long> powers ;

            while(n){
                long long power = biggestpower(n) ;
                powers.push_back(power) ;
                n -= power ;
            }

            sort(powers.begin() , powers.end()) ;       

            vector<long long> pfx(1 , 1) ;
            
            for(auto it : powers){
                pfx.push_back(it * pfx.back() % MOD) ;
            }
            vector<int> ans ;
            for(auto it : queries){
                ans.push_back(pfx[it[1] + 1] * invmod(pfx[it[0]]) % MOD) ;
            }

            return ans ;

    }
};