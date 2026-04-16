class Solution {
    using ll = long long ;

public:

    bool check(ll mid, vector<vector<int>> &grid){
        int n= grid.size(), m = grid[0].size() ;
        vector<vector<int>> dp(n, vector<int> (m , INT_MIN)) ;
        dp[0][0] = mid + grid[0][0] ;
        for(int i = 0 ;i < n ;i++ ){
            for(int j = 0 ; j < m ;j ++ ){
                if(i == 0 && j == 0) continue ;

                if(i > 0 && dp[i - 1][j] > 0) dp[i][j] = max(dp[i][j], grid[i][j] + dp[i - 1][j]) ;
                
                if(j > 0 && dp[i][j - 1] > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1] + grid[i][j]) ;
            }
        }

        return dp[n - 1][m - 1] > 0 ;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size() ;

        ll low = 1, high = 1e6 , ans = -1 ;

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX)) ;

        for(int i = 0;i < n ; i++ ){
            for(int j = 0 ; j < m ; j++ ){
                dungeon[i][j] = - dungeon[i][j] ;
            }
        }

        dp[n - 1][m - 1] = max(1, dungeon[n - 1][m - 1] + 1) ;
        for(int i= n - 1; i >= 0 ; i-- ){
            for(int j = m - 1 ; j >= 0 ; j-- ){
                if(i == n - 1 && j == m - 1) continue ;

                if(i < n - 1) {
                    int num = max(1, dp[i + 1][j] + dungeon[i][j]) ;
                    dp[i][j] = min(num, dp[i][j]) ;
                }

                if(j < m - 1) {
                    int num = max(1, dp[i][j + 1] + dungeon[i][j]) ;
                    dp[i][j] = min(num, dp[i][j]) ;
                }
            }
        }

        return dp[0][0] ;
    }
};