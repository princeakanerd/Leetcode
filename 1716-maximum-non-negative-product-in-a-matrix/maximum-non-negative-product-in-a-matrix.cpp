class Solution {
public:
    using ll = long long ;
    const int mod = 1e9 + 7 ;
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size() ;

        vector<vector<ll>> maxi(n, vector<ll> (m, LLONG_MIN)), mini(n, vector<ll> (m, LLONG_MAX) );
        maxi[0][0] = mini[0][0] = grid[0][0] ;

        // dp[i][j] represnts best possible ans to reach i, j from 0, 0
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < m ;j++ ){
                if(i == 0 && j == 0 ) continue ;

                if(i > 0){
                    maxi[i][j] = max(maxi[i][j], maxi[i - 1][j] * grid[i][j]) ;
                    maxi[i][j] = max(maxi[i][j], mini[i - 1][j] * grid[i][j]) ;

                    mini[i][j] = min(mini[i][j], mini[i - 1][j] * grid[i][j]) ;
                    mini[i][j] = min(mini[i][j], maxi[i - 1][j] * grid[i][j]) ;
                }

                if(j > 0){
                    maxi[i][j] = max(maxi[i][j], maxi[i][j - 1] * grid[i][j]) ;
                    maxi[i][j] = max(maxi[i][j], mini[i][j - 1] * grid[i][j]) ;
                    mini[i][j] = min(mini[i][j], mini[i][j - 1] * grid[i][j]) ;
                    mini[i][j] = min(mini[i][j], maxi[i][j - 1] * grid[i][j]) ;
                }
            }
        }

        if(maxi[n - 1][m - 1] < 0){
            return -1 ;
        }
        
        return maxi[n - 1][m - 1] % mod ;
    }
};