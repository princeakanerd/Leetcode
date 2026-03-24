class Solution {
    const int mod = 12345 ;
public:

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size() ;
        int prod = 1 ;

        vector<vector<int>> s(n, vector<int> (m, 1)), p(n, vector<int>(m, 1)) ;
        for(int i = 0 ; i < n ;i++ ){
            for(int j= 0 ; j < m ; j++ ){
                p[i][j] = prod ;
                prod = 1ll * prod * grid[i][j] % mod ;
            }
        }
        prod = 1;

        for(int i = n - 1 ; i >= 0 ; i-- ){
            for(int j = m - 1 ; j >= 0 ; j-- ){
                s[i][j] = prod ;
                prod = 1ll * prod * grid[i][j] % mod ;
            }
        }
        vector<vector<int>> res(n, vector<int>(m)) ;
        for(int i = 0 ; i < n ;i++ ){
            for(int j = 0 ;j < m ;j++ ){
                res[i][j] = 1ll * s[i][j] * p[i][j] % mod ;
            }
        }
        return res;
    }
};