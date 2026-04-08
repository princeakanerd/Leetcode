class Solution {
    using ll = long long ;
public:
    int f(vector<int> &a, int k){
        int n = a.size() ;

        // dp[i][j] states min number of operations to build j peaks uptil index i
        // create 3 diff arrays to handle cyclic
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX)) ;

        // ways to build 0 peaks is 0 
        for(int i = 0; i <= n ;i++ ){
            dp[i][0] = 0 ;
        }

        for(int i = 1 ; i < n ; i++ ){
            int num = max(a[i - 1] - a[i], a[(i + 1) % n] - a[i]) ;
            int cost = (num >= 0) ? num + 1 : 0;
            
            if(i == 1) {
                dp[i][1] = cost ;
                continue ;
            }
            for(int j = 1 ; j <= k ; j++ ){
                if(dp[i - 2][j - 1] != INT_MAX) dp[i][j] = min(dp[i][j], dp[i - 2][j - 1] + cost) ;
                dp[i][j] = min(dp[i][j], dp[i - 1][j]) ;
            }
        }

        return dp[n - 1][k] ;
    }
    int minOperations(vector<int>& a, int k) {
        if(k == 0) return 0 ;
        ll res = INT_MAX ;
        vector<int> temp1, temp2 ;
        int n = a.size() ;
        for(int i = 1 ;i < n ;i++ ) temp1.push_back(a[i]) ;
        temp1.push_back(a[0]) ;

        temp2.push_back(a.back()) ;

        for(int i = 0 ; i < n - 1 ;i++ ) temp2.push_back(a[i]) ;
        res = min({f(a, k), f(temp1, k), f(temp2, k)}) ;

        if(res == INT_MAX) return -1 ;
        return res ;

    }
};