class Solution {
    using ll = long long ;
public:
    long long minIncrease(vector<int>& a) {
        int n = a.size() ;

        // dp[i][0] represents the total number of operations required till index i to achieve that maximum given that no double skips have happened
        //  dp[i][1] represents the total number of operations required till index i to achieve that maximum given that 1 double skip has happened 

        // dp[i][1] = min(dp[i - 2][1], dp[i - 3][0]) ;
        // dp[i][0] = dp[i - 2][0]
        vector<vector<ll>> dp(n, vector<ll>(2, 1e18)) ;
        if(n > 1) dp[1][0] = 0; 
        if(n > 2) dp[2][1] = 0;

        if(n % 2){
            ll res = 0 ;

            for(int i = 1 ; i < n - 1 ; i += 2){
                if(a[i + 1] < a[i] && a[i - 1] < a[i]) continue ;
                res += 1 + max(a[i - 1] - a[i], a[i + 1] - a[i]) ;
            }
            return res;
        }

        for(int i = 1 ; i < n - 1 ;i++ ){
            ll num = max(a[i - 1] - a[i], a[i + 1] - a[i]) ;
            ll cost = (num >= 0) ? num + 1 : 0;
            if(i >= 3){
                dp[i][1] = dp[i - 2][1] ;
                dp[i][0] = dp[i - 2][0] ;
            }

            if(i >= 4){
                dp[i][1] = min(dp[i - 3][0], dp[i][1]);
            }

            if (dp[i][0] != 1e18) {
                dp[i][0] += cost; 
            }
            if (dp[i][1] != 1e18) {
                dp[i][1] += cost;
            }
            
        }

        // for(int i = 0 ; i < n ; i++ ){
        //     cout << dp[i][0] << " " << dp[i][1] << endl;
        // }

        return min({dp[n - 2][1], dp[n - 2][0], dp[n - 3][1], dp[n - 3][0]}) ;
    }
};