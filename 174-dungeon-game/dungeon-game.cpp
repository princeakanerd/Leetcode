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

        while(low <= high){
            ll mid = low + (high - low) / 2;

            if(check(mid, dungeon)){
                ans = mid ;
                high = mid - 1;
            } else low = mid + 1 ;
        }

        return ans ;
    }
};