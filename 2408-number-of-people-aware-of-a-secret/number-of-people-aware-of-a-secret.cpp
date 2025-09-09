class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        

        vector<long long> dp(n, 0) ;
        dp[0] = 1 ;
        long long MOD = 1e9 + 7 ;
        long long lastvalididx = n - forget ;
        long long res = 0 ;
        for(int i = 0 ; i < n ; i++ ){
            for(int j = delay + i ; j < min(n, i + forget) ;j++ ){
                dp[j] = (dp[i] + dp[j]) % MOD ;
            }

            if(i >= lastvalididx) res = (res + dp[i]) % MOD ;
        }
        
        return res ;


    

        

    }
};