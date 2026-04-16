class Solution {
public:
    int maximalSquare(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size() ;

        vector<vector<int>> left(n, vector<int>(m, 0)), up(n, vector<int>(m, 0)) ;
        for(int i = 0 ; i <n ;i++ ){
            int last = -1 ;
            for(int j= 0 ;j < m ;j ++ ){
                left[i][j] = last ;
                if(grid[i][j] == '0') last = j ;
            }
        }

        for(int j = 0 ; j < m ; j++ ){
            int last = -1 ;
            for(int i = 0; i < n ;i++ ){
                up[i][j] = last ;
                if(grid[i][j] == '0') last = i ;
            }
        }

        vector<vector<int>> dp(n, vector<int>(m)) ;

        for(int i= 0;i < n ;i++){
            for(int j= 0;j < m ;j++ ){
                dp[i][j] = (grid[i][j] - '0') ;
            }
        }

        // dp[i][j] states the maximum length of the side of square possible with all ones which has bottom right corner at i,j ;
        for(int i = 1 ;i < n ;i++ ){
            for(int j = 1; j < m ; j++ ){
                if(grid[i][j] == '1'){
                    dp[i][j] = max(dp[i][j], min({1 + dp[i -1][j - 1], i - up[i][j], j - left[i][j]})) ;
                }
            }
        }

        int res = 0 ;
        
        for(int i = 0 ;i <n ;i++ ){
            for(int j= 0 ; j < m ; j++ ){
                res = max(res, dp[i][j] * dp[i][j]) ;
            }
        }
    
        return res;
    }
};