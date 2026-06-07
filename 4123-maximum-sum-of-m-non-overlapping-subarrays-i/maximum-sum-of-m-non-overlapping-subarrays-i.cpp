class Solution {
    using ll = long long ;
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size() ;
        
        vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1e15)) ;

        vector<ll> pfx(1, 0) ;
        for(int i = 0 ; i < n ;i++ ){
            pfx.push_back(pfx.back() + nums[i]) ;
        }

        for(int i = 0 ; i <= n ;i++) dp[i][0] = 0 ;

        for(ll j = 1 ;j <= m ; j++ ){
            deque<pair<long long, long long>> dq; 
            for(ll i = 1 ; i <= n ; i++ ){

                while(dq.size() && dq.front().first < i - r) dq.pop_front() ;
                
                if(i - l >= 0) {
                    ll val = dp[i - l][j - 1] - pfx[i - l];
                    while(dq.size() && dq.back().second <= val) dq.pop_back() ;
                    dq.push_back(make_pair(i - l, val)) ;
                }

                dp[i][j] = max(dp[i - 1][j], pfx[i] + dq.front().second) ;
            }
        }

        ll ans = -1e15 ;
        for(int j = 1 ; j <= m ;j++ ){
            ans = max(ans, dp[n][j]) ;
        }

        return ans ;


        

        
    }
};