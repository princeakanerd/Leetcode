class Solution {
    using ll = long long ;
public:
    ll f(int i, ll rem, vector<int> &cost, vector<int> &time,vector<vector<int>> &dp){
        if(rem <= 0) return 0 ;
        if(i == cost.size()){
            return 1e9 ;
        }
        

        if(dp[i][rem] != -1) return dp[i][rem] ;
        ll l = cost[i] + f(i + 1, rem - 1 - time[i], cost , time, dp) ;
        ll r = f(i + 1, rem, cost, time, dp) ;

        return dp[i][rem] = min(l, r) ;
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size() ;
        vector<vector<int>> dp(n, vector<int> (n + 1 , -1)) ;

        return f(0, n, cost, time, dp) ;


    }
};