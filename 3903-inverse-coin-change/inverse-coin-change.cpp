class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size() ;
        vector<long long> dp(n + 1 ,0) ;
        dp[0] = 1 ;
        vector<int> res ;
        for(int i = 1 ; i <= n ; i++ ) {

            if(numWays[i - 1] < dp[i] || numWays[i - 1] > dp[i] + 1) return {} ;

            if(numWays[i - 1] == dp[i] + 1) {
                res.push_back(i) ;
                for(int j = i ; j <= n ; j++) {
                    dp[j] += dp[j - i] ;
                }
            }
        }
        return res ;
    }
};